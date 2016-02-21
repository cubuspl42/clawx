#include "Renderer.h"

#include "utils.h"

#include <fstream>
#include <sstream>

static const std::string SURFACE_VERTEX_SHADER = "surface.vert";
static const std::string SURFACE_FRAGMENT_SHADER = "surface.frag";
static const std::string FRONTBUFFER_VERTEX_SHADER = "frontbuffer.vert";
static const std::string FRONTBUFFER_FRAGMENT_SHADER = "frontbuffer.frag";

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
}

void Renderer::LoadSurfaceProgram() {
	GLuint vertexShader = create_shader(GL_VERTEX_SHADER, SURFACE_VERTEX_SHADER);
	GLuint fragmentShader = create_shader(GL_FRAGMENT_SHADER, SURFACE_FRAGMENT_SHADER);

	surface_program = create_program(vertexShader, fragmentShader);

	assert(!glGetError());

	GLint u = glGetUniformLocation(surface_program, "surface_texture");
	if (u >= 0)
		glUniform1i(u, 0);

	assert(!glGetError());
}

void Renderer::LoadFrontbufferProgram() {
	assert(!glGetError());

	GLuint vertexShader = create_shader(GL_VERTEX_SHADER, FRONTBUFFER_VERTEX_SHADER);
	GLuint fragmentShader = create_shader(GL_FRAGMENT_SHADER, FRONTBUFFER_FRAGMENT_SHADER);

	frontbuffer_program = create_program(vertexShader, fragmentShader);

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

Renderer::Renderer(HWND hwnd, int window_width, int window_height)
	: window_width(window_width), window_height(window_height)
{
	InitGl();

	LoadSurfaceProgram();
	LoadFrontbufferProgram();
}

Renderer::~Renderer()
{
}

Renderer::Surface Renderer::CreateSurface(int width, int height, bool fb)
{
	Renderer::Surface surface(width, height, surface_program);
	

	return surface;
}

void Renderer::SetPalette(Palette * palette)
{
	this->palette = palette;
}

void Renderer::Render(int x, int y, int sx_, int sy_, int color_key, Surface * a, Surface * b) {
	CreateFramebuffer(a);

	assert(!glGetError());

	glViewport(0, 0, FRONTBUFFER_WIDTH, FRONTBUFFER_HEIGHT);

	assert(!glGetError());

	GLuint fbo = a->fbo;
	GLuint program = surface_program;
	auto &surface = *b;

	glUseProgram(program);

	check_gl_error();

	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	check_gl_error();

	glm::mat4 trans;

	if (fbo == 0) {
		trans = glm::scale(trans, { 1, -1, 1 });
	}

	trans = glm::translate(trans, { -1, -1, 0 });

	float sx = 2 / 640.f;
	float sy = 2 / 480.f;

	trans = glm::scale(trans, { sx, sy, 1 });

	trans = glm::translate(trans, { x, y, 0 });

	trans = glm::scale(trans, { sx_, sy_, 0 });

	GLint uniTrans = glGetUniformLocation(program, "trans");
	if (uniTrans >= 0)
		glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

	GLint uniCk = glGetUniformLocation(program, "color_key");
	if (uniCk >= 0)
		glUniform1i(uniCk, color_key);

	assert(!glGetError());

	glBindVertexArray(surface.vao);

	assert(!glGetError());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, surface.texture);

	assert(!glGetError());

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	assert(!glGetError());
}

void Renderer::Clear(Surface * surface, int color_index)
{
 	CreateFramebuffer(surface);
	glBindFramebuffer(GL_FRAMEBUFFER, surface->fbo);

	glClearColor(color_index / 255.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
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
