#define DLL_NAME "PROXY"

// Include GLEW
#include <GL/glew.h>

#include "log.h"
#include "proxy.h"
#include "dump.h"

#include "json.hpp"
#include "stb_image_write.h"

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <unordered_map>

#define config (GetProxy()->GetConfig())

using json = nlohmann::json;

const unsigned MAGIC = 0x1a1b1c00;

bool DISABLE_PROXY = false;

sf::Window *window;

template<typename T>
size_t h(const T* ptr) {
	const char *c = (const char *)ptr;
	int n = sizeof(T);
	std::size_t seed = 0;
	for (int i = 0; i < n; ++i) {
		char j = c[i];
		seed ^= j + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	}
	return seed;
}

size_t h_ddsd00(DDSURFACEDESC *ddsd) {
	DDSURFACEDESC ddsd00 = *ddsd;
	ddsd00.dwWidth = ddsd00.dwHeight = 0;
	return h(&ddsd00);
}

#define PROXY_UNIMPLEMENTED() 0

#define DDRAW_PALETTE_PROXY(method)

struct DirectDrawPaletteProxy : public IDirectDrawPalette
{
	const unsigned PALETTE_SIZE = 256;

	std::vector<PALETTEENTRY> entries;

	DirectDrawPaletteProxy() {
		entries.resize(PALETTE_SIZE);
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PALETTE_PROXY(QueryInterface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_PALETTE_PROXY(AddRef);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_PALETTE_PROXY(Release);
		return PROXY_UNIMPLEMENTED();
	}
	/*** IDirectDrawPalette methods ***/
	STDMETHOD(GetCaps)(THIS_ LPDWORD) {
		DDRAW_PALETTE_PROXY(GetCaps);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetEntries)(
		DWORD          dwFlags,
		DWORD          dwBase,
		DWORD          dwNumEntries,
		LPPALETTEENTRY lpEntries
	) {
		DDRAW_PALETTE_PROXY(GetEntries);

		assert(dwBase == 0 && dwNumEntries == PALETTE_SIZE);

		for (int i = 0; i < PALETTE_SIZE; ++i) {
			lpEntries[i] = entries[i];
		}

		return S_OK;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, DWORD, LPPALETTEENTRY) {
		DDRAW_PALETTE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetEntries)(
		DWORD          dwFlags,
		DWORD          dwStartingEntry,
		DWORD          dwCount,
		LPPALETTEENTRY lpEntries
	) {
		DDRAW_PALETTE_PROXY(SetEntries);

		assert(dwStartingEntry == 0 && dwCount == PALETTE_SIZE);

		for (int i = 0; i < PALETTE_SIZE; ++i) {
			entries[i] = lpEntries[i];
		}

		std::vector<byte> texture_data(PALETTE_SIZE * 4);

		for (int i = 0; i < PALETTE_SIZE; ++i) {
			auto &e = entries[i];
			byte *px = &texture_data[i * 4];
			px[0] = e.peRed;
			px[1] = e.peGreen;
			px[2] = e.peBlue;
			px[3] = 0xFF;
		}

		return S_OK;
	}
};

#define DDRAW_SURFACE_PROXY(method) log_call("DirectDrawSurfaceProxy", #method, this);

#define _DDSCL_NORMAL 0

int fileExists(TCHAR * file)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(file, &FindFileData);
	int found = handle != INVALID_HANDLE_VALUE;
	if (found)
	{
		//FindClose(&handle); this will crash
		FindClose(handle);
	}
	return found;
}

size_t ddsd00_h(LPDDSURFACEDESC ddsd) {
	DDSURFACEDESC ddsd00 = *ddsd;
	ddsd00.dwWidth = ddsd00.dwHeight = 0;
	ddsd00.lpSurface = nullptr;
	return h(&ddsd00);
}

class DirectDrawProxy;
class DirectDrawSurfaceProxy;

DirectDrawSurfaceProxy *front_buffer;
DirectDrawSurfaceProxy *back_buffer;

std::vector<char> buffer(1920 * 1080 * 4);

GLuint shaderProgram;

class DirectDrawSurfaceProxy : public IDirectDrawSurface3
{
public:
	enum Kind {
		NORMAL_SURFACE,
		FRONT_BUFFER,
		BACK_BUFFER
	};

	int magic = MAGIC;

	DirectDrawProxy *ddp = nullptr;
	Kind kind;
	size_t d_h = 0;
	int width = 0;
	int height = 0;
	int pitch = 0;

	std::vector<UCHAR> indexed_buffer;

	DirectDrawPaletteProxy *ddpp = nullptr;

	GLuint vao;
	GLuint texture;

	DirectDrawSurfaceProxy(DirectDrawProxy *ddp, Kind kind, size_t d_h, int width, int height, int pitch) {
		this->ddp = ddp;
		this->kind = kind;
		this->d_h = d_h;
		this->width = width;
		this->height = height;
		this->pitch = pitch;

		indexed_buffer.resize(640 * 480 * 4); // ...

											  // Create Vertex Array Object
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		// Create an element array
		GLuint ebo;
		glGenBuffers(1, &ebo);

		GLuint elements[] = {
			0, 1, 2,
			2, 3, 0
		};

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

		// Create a Vertex Buffer Object and copy the vertex data to it
		GLuint vbo;
		glGenBuffers(1, &vbo);

		GLfloat vertices[] = {
			//  Position      Texcoords
			0,  0, 0.0f, 0.0f, // Top-left
			width,  0, 1.0f, 0.0f, // Top-right
			width, height, 1.0f, 1.0f, // Bottom-right
			0, height, 0.0f, 1.0f  // Bottom-left
		};

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Specify the layout of the vertex data
		GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
		glEnableVertexAttribArray(posAttrib);
		glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);

		GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
		glEnableVertexAttribArray(texAttrib);
		glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));


		// Load textures
		glGenTextures(1, &texture);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_SURFACE_PROXY(QueryInterface);

		*ppvObj = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_SURFACE_PROXY(AddRef);
		return S_OK;
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_SURFACE_PROXY(Release);
		return S_OK;
	}
	/*** IDirectDrawSurface methods ***/
	STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE_PROXY(AddAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT) {
		DDRAW_SURFACE_PROXY(AddOverlayDirtyRect);
		return PROXY_UNIMPLEMENTED();
	}

	void Draw(int x, int y) {
		glm::mat4 pos;
		pos = glm::translate(pos, { x + 0.5, y + 0.5, 0 });
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "pos"), 1, GL_FALSE, glm::value_ptr(pos));

		glm::mat2 surface_m;
		surface_m = { float(width) / pitch, 0, 0, 1 };
		glUniformMatrix2fv(glGetUniformLocation(shaderProgram, "surface_m"), 1, GL_FALSE, glm::value_ptr(surface_m));

		glBindVertexArray(vao);

		glBindTexture(GL_TEXTURE_2D, texture);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	STDMETHOD(Blt)(
		 LPRECT               lpDestRect,
		 LPDIRECTDRAWSURFACE3 lpDDSrcSurface,
		 LPRECT               lpSrcRect,
		 DWORD                dwFlags,
		 LPDDBLTFX            lpDDBltFx
	) {
		DDRAW_SURFACE_PROXY(Blt);

		if (!lpDDSrcSurface) {
			return S_OK;
		}

		if (kind == NORMAL_SURFACE) {
			return S_OK;
		}

		int x = 0;
		int y = 0;

		if (lpDestRect) {
			x = lpDestRect->left;
			y = lpDestRect->top;
		}

		if (lpSrcRect) {
			//x -= lpSrcRect->left;
			//y -= lpSrcRect->top;
		}

		DirectDrawSurfaceProxy *ddsd = (DirectDrawSurfaceProxy *)lpDDSrcSurface;

		//dump("_blt");

		return S_OK;
	}

	STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD) {
		DDRAW_SURFACE_PROXY(BltBatch);
		return PROXY_UNIMPLEMENTED();
	}

	STDMETHOD(BltFast)(THIS_
		DWORD                dwX,
		DWORD                dwY,
		LPDIRECTDRAWSURFACE3 lpDDSrcSurface,
		LPRECT               lpSrcRect,
		DWORD                dwFlags
	) {
		DDRAW_SURFACE_PROXY(BltFast);

		if (kind == NORMAL_SURFACE) {
			return S_OK;
		}

		int x = dwX;
		int y = dwY;

		if (lpSrcRect) {
			//x -= lpSrcRect->left;
			//y -= lpSrcRect->top;
		}

		DirectDrawSurfaceProxy *ddsp = (DirectDrawSurfaceProxy *)lpDDSrcSurface;

		ddsp->Draw(x, y);

		return S_OK;
	}

	STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD, LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE_PROXY(DeleteAttachedSurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_SURFACE_PROXY(EnumAttachedSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD, LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_SURFACE_PROXY(EnumOverlayZOrders);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE3 a, DWORD b) {
		DDRAW_SURFACE_PROXY(Flip);

		static int i = 0;
		++i;
		if (i % 5 == 0)
			GetProxy()->ReloadConfig();

		window->display();

		glClear(GL_COLOR_BUFFER_BIT);

		return S_OK;
	}
	STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR *out_dds) {
		DDRAW_SURFACE_PROXY(GetAttachedSurface);

		auto ddsp = new DirectDrawSurfaceProxy(ddp, BACK_BUFFER, d_h, width, height, width);
		*out_dds = ddsp;

		back_buffer = ddsp;
			
		return S_OK;
	}
	STDMETHOD(GetBltStatus)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(GetBltStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDSCAPS) {
		DDRAW_SURFACE_PROXY(GetCaps);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*) {
		DDRAW_SURFACE_PROXY(GetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY) {
		DDRAW_SURFACE_PROXY(GetColorKey);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDC)(THIS_ HDC FAR *a) {
		DDRAW_SURFACE_PROXY(GetDC);

		*a = (HDC)1;

		return S_OK;
	}
	STDMETHOD(GetFlipStatus)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(GetFlipStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG) {
		DDRAW_SURFACE_PROXY(GetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*) {
		DDRAW_SURFACE_PROXY(GetPalette);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT a) {
		DDRAW_SURFACE_PROXY(GetPixelFormat);
		return S_OK;
	}
	STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_SURFACE_PROXY(GetSurfaceDesc);

		std::string s = "GetSurfaceDesc_" + std::to_string(d_h);

		Load(s, a);

		a->dwWidth = width;
		a->dwHeight = height;

		pitch = a->lPitch;

		if (pitch < width) {
			pitch = 640;
		}

		return S_OK;
	}
	STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC) {
		DDRAW_SURFACE_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(IsLost)(THIS) {
		DDRAW_SURFACE_PROXY(IsLost);
		return 0;
	}
	STDMETHOD(Lock)(THIS_ LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d) {
		DDRAW_SURFACE_PROXY(Lock);

		Load("Lock_" + std::to_string(d_h), b);
		b->dwWidth = width;
		b->dwHeight = height;

		b->lpSurface = indexed_buffer.data();

		//dump("_lock");

		return S_OK;
	}
	STDMETHOD(ReleaseDC)(THIS_ HDC a) {
		DDRAW_SURFACE_PROXY(ReleaseDC);
		return S_OK;
	}
	STDMETHOD(Restore)(THIS) {
		DDRAW_SURFACE_PROXY(Restore);
		return S_OK;
	}
	STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER) {
		DDRAW_SURFACE_PROXY(SetClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetColorKey)(THIS_ DWORD a, LPDDCOLORKEY b) {
		DDRAW_SURFACE_PROXY(SetColorKey);
		return S_OK;
	}
	STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG) {
		DDRAW_SURFACE_PROXY(SetOverlayPosition);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE a) {
		DDRAW_SURFACE_PROXY(SetPalette);
		
		ddpp = (DirectDrawPaletteProxy *)a;

		return S_OK;
	}

	void dump(std::string p) {
#if 0
		if (indexed_buffer.size() && fileExists("dump")) {
			static int i = 0;
			int p = width;
			if (pitch > 0 && pitch < 1024) p = pitch;

			auto rgbab = indexed2rgba((UCHAR*)indexed_buffer.data(), width, height, p);

			char t[64];

			const char *tp = "sf";
			if (kind == FRONT_BUFFER) tp = "fb";
			if (kind == BACK_BUFFER) tp = "bb";

			sprintf_s(t, "d/%05d_%p_%s_%s.png", i++, this, tp, unlock ? "unlock": "lock");

			stbi_write_bmp(t, width, height, 4, rgbab.data());
		}
#else
		if (fileExists("dump")) {
			static int i = 0;

			char t[64];

			const char *tp = "sf";
			if (kind == FRONT_BUFFER) tp = "fb";
			if (kind == BACK_BUFFER) tp = "bb";

			sprintf_s(t, "d/%05d_%p_%s_%s.bmp", i++, this, tp, p.c_str());

			//stbi_write_bmp(t, width, height, 4, pixels);
		}
#endif
	}

	STDMETHOD(Unlock)(THIS_ LPVOID a) {
		DDRAW_SURFACE_PROXY(Unlock);

		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, pitch, height, 0, GL_RED, GL_UNSIGNED_BYTE, indexed_buffer.data());

		//dump("_unlock");
			
		return S_OK;
	}

	STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE3, LPRECT, DWORD, LPDDOVERLAYFX) {
		DDRAW_SURFACE_PROXY(UpdateOverlay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(UpdateOverlayDisplay);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE3) {
		DDRAW_SURFACE_PROXY(UpdateOverlayZOrder);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetDDInterface)(THIS_ LPVOID FAR *) {
		DDRAW_SURFACE_PROXY(GetDDInterface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(PageLock)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(PageLock);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(PageUnlock)(THIS_ DWORD) {
		DDRAW_SURFACE_PROXY(PageUnlock);
		return PROXY_UNIMPLEMENTED();
	}
	/*** Added in the V3 interface ***/
	STDMETHOD(SetSurfaceDesc)(THIS_ LPDDSURFACEDESC a, DWORD b) {
		DDRAW_SURFACE_PROXY(SetSurfaceDesc);
		return PROXY_UNIMPLEMENTED();
	}
};

#define DDRAW_PROXY(method) log_call("DirectDrawProxy", #method, this);

struct DirectDrawProxy : public IDirectDraw2
{
	DirectDrawSurfaceProxy *GetFrontBuffer() {
		return front_buffer;
	}

	DirectDrawSurfaceProxy *GetBackBuffer() {
		return back_buffer;
	}

	DirectDrawProxy() {
		// Shader sources
		const GLchar* vertexSource =
			"#version 150 core\n"
			"in vec2 position;"
			"in vec2 texcoord;"
			"out vec2 Texcoord;"
			"uniform mat4 trans;"
			"uniform mat4 pos;"
			"void main()"
			"{"
			"    Texcoord = texcoord;"
			"    gl_Position = trans * pos * vec4(position, 0.0, 1.0);"
			"}";
		const GLchar* fragmentSource =
			"#version 150 core\n"
			"in vec2 Texcoord;"
			"out vec4 outColor;"
			"uniform mat2 surface_m;"
			"uniform sampler2D surface_texture;"
			"void main()"
			"{"
			"    outColor = texture(surface_texture, surface_m * Texcoord);"
			"}";

		// Initialize GLEW
		glewExperimental = GL_TRUE;
		glewInit();

		// Create and compile the vertex shader
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		glCompileShader(vertexShader);

		// Create and compile the fragment shader
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShader);

		// Link the vertex and fragment shader into a shader program
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glBindFragDataLocation(shaderProgram, 0, "outColor");
		glLinkProgram(shaderProgram);
		glUseProgram(shaderProgram);

		glm::mat4 trans;
		trans = glm::translate(trans, { -1, 1, 0 });
		trans = glm::scale(trans, { 1, -1, 1 });
		float sx = 1 / 640.f * 2;
		float sy = 1 / 480.f * 2;
		trans = glm::scale(trans, { sx, sy, 1 });

		GLint uniTrans = glGetUniformLocation(shaderProgram, "trans");
		glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

		glUniform1i(glGetUniformLocation(shaderProgram, "surface_texture"), 0);
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR * ppvObj) {
		DDRAW_PROXY(QueryInterface);

		*ppvObj = this;

		return S_OK;
	}
	STDMETHOD_(ULONG, AddRef) (THIS) {
		DDRAW_PROXY(AddRef);
		return S_OK;
	}
	STDMETHOD_(ULONG, Release) (THIS) {
		DDRAW_PROXY(Release);
		return S_OK;
	}
	/*** IDirectDraw methods ***/
	STDMETHOD(Compact)(THIS) {
		DDRAW_PROXY(Compact);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreateClipper)(THIS_ DWORD a, LPDIRECTDRAWCLIPPER FAR* b, IUnknown FAR *c) {
		DDRAW_PROXY(CreateClipper);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(CreatePalette)(THIS_ DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR* out_ddp, IUnknown FAR *d) {
		DDRAW_PROXY(CreatePalette);

		auto ddpp = new DirectDrawPaletteProxy();
		*out_ddp = ddpp;
		
		return S_OK;
	}
	STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC ddsd, LPDIRECTDRAWSURFACE FAR *out_dds, IUnknown FAR *c) {
		DDRAW_PROXY(CreateSurface);

		DirectDrawSurfaceProxy::Kind kind = DirectDrawSurfaceProxy::NORMAL_SURFACE;

		int width = ddsd->dwWidth;
		int height = ddsd->dwHeight;

		if (ddsd->dwBackBufferCount) {
			kind = DirectDrawSurfaceProxy::FRONT_BUFFER;
			width = config["backbuffer_w"];
			height = config["backbuffer_h"];
		}

		size_t d_h = kind == DirectDrawSurfaceProxy::FRONT_BUFFER ? h(ddsd) : ddsd00_h(ddsd);

		DirectDrawSurfaceProxy *ddsp = new DirectDrawSurfaceProxy(this, kind, d_h, width, height, width);

		if (kind == DirectDrawSurfaceProxy::FRONT_BUFFER) {
			front_buffer = ddsp;
		}

		*out_dds = (IDirectDrawSurface*)ddsp;

		return S_OK;
	}
	STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR *b) {
		DDRAW_PROXY(DuplicateSurface);
		return PROXY_UNIMPLEMENTED();
	}

	STDMETHOD(EnumDisplayModes)(THIS_ DWORD a, LPDDSURFACEDESC b, LPVOID user_ptr, LPDDENUMMODESCALLBACK callback) {
		DDRAW_PROXY(EnumDisplayModes);

		DDSURFACEDESC ddsd;

		Load("EnumDisplayModes_0", &ddsd);
		callback(&ddsd, user_ptr);

		Load("EnumDisplayModes_1", &ddsd);
		callback(&ddsd, user_ptr);

		Load("EnumDisplayModes_2", &ddsd);
		callback(&ddsd, user_ptr);

		return S_OK;
	}
	STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK) {
		DDRAW_PROXY(EnumSurfaces);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(FlipToGDISurface)(THIS) {
		DDRAW_PROXY(FlipToGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetCaps)(THIS_ LPDDCAPS a, LPDDCAPS b) {
		DDRAW_PROXY(GetCaps);

		Load("GetCaps_a", a);
		Load("GetCaps_b", a);

		return S_OK;
	}
	STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC a) {
		DDRAW_PROXY(GetDisplayMode);

		Load("EnumDisplayModes_0", a);

		return S_OK;
	}
	STDMETHOD(GetFourCCCodes)(THIS_  LPDWORD, LPDWORD) {
		DDRAW_PROXY(GetFourCCCodes);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR *) {
		DDRAW_PROXY(GetGDISurface);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD) {
		DDRAW_PROXY(GetMonitorFrequency);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetScanLine)(THIS_ LPDWORD) {
		DDRAW_PROXY(GetScanLine);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL) {
		DDRAW_PROXY(GetVerticalBlankStatus);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(Initialize)(THIS_ GUID FAR *) {
		DDRAW_PROXY(Initialize);
		return PROXY_UNIMPLEMENTED();
	}
	STDMETHOD(RestoreDisplayMode)(THIS) {
		DDRAW_PROXY(RestoreDisplayMode);
		return S_OK;
	}
	STDMETHOD(SetCooperativeLevel)(THIS_ HWND hWnd, DWORD flags) {
		DDRAW_PROXY(SetCooperativeLevel);
		return S_OK;
	}
	STDMETHOD(SetDisplayMode)(THIS_ DWORD w, DWORD h, DWORD c, DWORD d, DWORD e) {
		DDRAW_PROXY(SetDisplayMode);
		return S_OK;
	}
	STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD a, HANDLE b) {
		DDRAW_PROXY(WaitForVerticalBlank);
		return S_OK;
	}
	/*** Added in the v2 interface ***/
	STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS, LPDWORD, LPDWORD) {
		DDRAW_PROXY(GetAvailableVidMem);
		return PROXY_UNIMPLEMENTED();
	};
};

class Proxy : public IProxy {
	json _config;
	std::ofstream _log;

public:

	Proxy() {
		ReloadConfig();

		std::string log_filename = _config["log_filename"];
		_log.open(log_filename.c_str());

		window = new sf::Window;
	}

	~Proxy() {}

	HWND CreateWindowExA(
		CreateWindowExA_type _CreateWindowExA,
		DWORD     dwExStyle,
		LPCTSTR   lpClassName,
		LPCTSTR   lpWindowName,
		DWORD     dwStyle,
		int       x,
		int       y,
		int       nWidth,
		int       nHeight,
		HWND      hWndParent,
		HMENU     hMenu,
		HINSTANCE hInstance,
		LPVOID    lpParam
	) {
		if (config["CreateWindowExA_disable_style"]) {
			dwStyle = 0;
		}

		nWidth = config["CreateWindowExA_nWidth"];
		nHeight = config["CreateWindowExA_nHeight"];

		HWND hWnd = _CreateWindowExA(
			dwExStyle,
			lpClassName,
			lpWindowName,
			dwStyle,
			x,
			y,
			nWidth,
			nHeight,
			hWndParent,
			hMenu,
			hInstance,
			lpParam
		);

		window->create(hWnd);

		bool vsync = config["vsync"];
		window->setVerticalSyncEnabled(vsync);

		return hWnd;
	}

	HRESULT DirectDrawProxyCreate(
		DirectDrawCreatePtr _DirectDrawCreate,
		GUID *lpGUID,
		LPDIRECTDRAW *lplpDD,
		IUnknown     *pUnkOuter
	) {
		auto ddp = new DirectDrawProxy();

		*lplpDD = (IDirectDraw *)ddp;

		return S_OK;
	}

	void ReloadConfig() {
		std::ifstream cfg_file;
		cfg_file.open("config.json");
		_config << cfg_file;
	}

	const json &GetConfig() {
		return _config;
	}

	void Log(std::string s) {
		_log << s;
		_log.flush();
	}
};

PROXY_EXPORTS IProxy *GetProxy() {
	static Proxy *proxy = nullptr;
	if (!proxy) {
		proxy = new Proxy();
	}
	return proxy;
}
