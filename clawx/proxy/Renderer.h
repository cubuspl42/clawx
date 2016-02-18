#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Windows.h>

#include <vector>

struct Renderer
{
	sf::Window window;

	std::vector<byte> palette_texture_buffer;
	GLuint palette_texture = 0;

	GLuint surface_program = 0;
	GLuint frontbuffer_program;

	void InitGl();

	void LoadSurfaceProgram();

	void LoadFrontbufferProgram();

public:

	static const unsigned PALETTE_SIZE = 256;

	Renderer(HWND hwnd);

	~Renderer();

	void SetPalette(LPPALETTEENTRY lpEntries);

};

