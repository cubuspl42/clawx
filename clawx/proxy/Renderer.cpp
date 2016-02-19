#include "Renderer.h"

#include <fstream>
#include <sstream>

static std::string read_file(std::string filename) {
	std::ifstream f(filename.c_str());
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}

GLuint create_shader(GLenum shader_type, std::string shader_name) {
	// Shader sources
	std::string source = read_file(shader_name);
	auto sourcePtr = source.c_str();

	// Create and compile the vertex shader
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &sourcePtr, NULL);
	glCompileShader(shader);

	char shader_log[1024];
	glGetShaderInfoLog(shader, 1024, NULL, shader_log);

	if (shader_log[0]) {
		MessageBox(0, shader_log, shader_name.c_str(), 0);
	}

	assert(!glGetError());

	return shader;
}

GLuint create_program(GLuint vertex_shader, GLuint fragment_shader) {
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex_shader);
	glAttachShader(shaderProgram, fragment_shader);

	glBindFragDataLocation(shaderProgram, 0, "outColor");

	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	char shaderProgramLog[1024];
	glGetProgramInfoLog(shaderProgram, 1024, NULL, shaderProgramLog);

	if (shaderProgramLog[0]) {
		MessageBox(0, shaderProgramLog, "shader program", 0);
	}

	assert(!glGetError());

	return shaderProgram;
}

void Renderer::InitGl() {
	glewExperimental = GL_TRUE;
	glewInit();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glViewport(0, 0, 640, 480);
}

void Renderer::LoadSurfaceProgram() {
	GLuint vertexShader = create_shader(GL_VERTEX_SHADER, "vertexShader.vert");
	GLuint fragmentShader = create_shader(GL_FRAGMENT_SHADER, "fragmentShader.frag");

	surface_program = create_program(vertexShader, fragmentShader);

	assert(!glGetError());

	GLint u = glGetUniformLocation(surface_program, "surface_texture");
	if (u >= 0)
		glUniform1i(u, 0);

	assert(!glGetError());
}

void Renderer::LoadFrontbufferProgram() {
	assert(!glGetError());

	GLuint vertexShader = create_shader(GL_VERTEX_SHADER, "vertexShader.vert");
	GLuint fragmentShader2 = create_shader(GL_FRAGMENT_SHADER, "fragmentShader2.frag");

	frontbuffer_program = create_program(vertexShader, fragmentShader2);

	assert(!glGetError());

	GLint u;

	u = glGetUniformLocation(frontbuffer_program, "surface_texture");
	if (u >= 0)
		glUniform1i(u, 0);

	assert(!glGetError());

	u = glGetUniformLocation(frontbuffer_program, "palette_texture");
	if (u >= 0)
		glUniform1i(u, 1);

	assert(!glGetError());
}



Renderer::Renderer(HWND hwnd)
{
	//window.create(hwnd);

	InitGl();

	LoadSurfaceProgram();
	LoadFrontbufferProgram();

	palette_texture_buffer.resize(PALETTE_SIZE * 4);

	glGenTextures(1, &palette_texture);

	glBindTexture(GL_TEXTURE_1D, palette_texture);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	assert(!glGetError());

}

Renderer::~Renderer()
{
}

Renderer::Surface Renderer::CreateSurface(int width, int height, bool fb)
{
	Renderer::Surface surface(width, height, surface_program);
	

	return surface;
}

void Renderer::SetPalette(LPPALETTEENTRY lpEntries)
{
	for (int i = 0; i < PALETTE_SIZE; ++i) {
		byte *px = &palette_texture_buffer[i * 4];
		auto &e = lpEntries[i];

		px[0] = e.peRed;
		px[1] = e.peGreen;
		px[2] = e.peBlue;
		px[3] = 0xFF;
	}

#if 0
	palette_texture_buffer[0] = 0;
	palette_texture_buffer[1] = 0;
	palette_texture_buffer[2] = 0;
	palette_texture_buffer[3] = 0;
#endif

	glBindTexture(GL_TEXTURE_1D, palette_texture);
	glTexImage1D(
		GL_TEXTURE_1D,
		0,
		GL_RGBA,
		PALETTE_SIZE,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		palette_texture_buffer.data());

	assert(!glGetError());
}

Renderer::Surface::Surface(Surface &&x)
{
	width = x.width;
	height = x.height;

	fbo = x.fbo;
	vao = x.vao;
	vbo = x.vbo;
	ebo = x.ebo;
	texture = x.texture;

	x.fbo = x.vbo = x.vao = x.ebo = x.texture = 0;

	texture_buffer = x.texture_buffer;
}

Renderer::Surface &Renderer::Surface::operator=(Renderer::Surface &&x)
{
	width = x.width;
	height = x.height;

	fbo = x.fbo;
	vao = x.vao;
	vbo = x.vbo;
	ebo = x.ebo;
	texture = x.texture;

	x.fbo = x.vbo = x.vao = x.ebo = x.texture = 0;

	texture_buffer = x.texture_buffer;

	return *this;
}

Renderer::Surface::Surface(int width, int height, GLuint program)
{
	this->width = width;
	this->height = height;

	texture_buffer.resize(width * height);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create an element array
	glGenBuffers(1, &ebo);

	GLuint elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	// Create a Vertex Buffer Object and copy the vertex data to it
	glGenBuffers(1, &vbo);

	int L = 0;
	int R = 1;
	int T = 0;
	int B = 1;

	GLfloat vertices[] = {
		//  Position      Texcoords
		0,		0,		L, T, // Top-left
		width,	0,		R, T, // Top-right
		width,	height, R, B, // Bottom-right
		0,		height, L, B  // Bottom-left
	};

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	assert(!glGetError());

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(program, "position");
	if (posAttrib >= 0) {
		glEnableVertexAttribArray(posAttrib);
		glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	}
	assert(!glGetError());

	GLint texAttrib = glGetAttribLocation(program, "texcoord");
	if (texAttrib >= 0) {
		glEnableVertexAttribArray(texAttrib);
		glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
	}

	assert(!glGetError());
	// Load textures
	glGenTextures(1, &texture);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, nullptr);

	assert(!glGetError());
}

Renderer::Surface::~Surface()
{
	if (texture) glDeleteTextures(1, &texture);
	if (vbo) glDeleteBuffers(1, &vbo);
	if (ebo) glDeleteBuffers(1, &ebo);
	if (vao) glDeleteVertexArrays(1, &vao);
}
