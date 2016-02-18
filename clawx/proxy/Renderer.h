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
	std::vector<byte> palette_texture_buffer;
	GLuint palette_texture = 0;

public:

	static const unsigned PALETTE_SIZE = 256;

	Renderer();

	~Renderer();

	void SetPalette(LPPALETTEENTRY lpEntries);

};

