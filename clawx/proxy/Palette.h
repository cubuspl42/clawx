#pragma once

#include <GL/glew.h>

#include <Windows.h>

#include <vector>

struct Palette
{
	std::vector<byte> palette_texture_buffer;
	GLuint palette_texture = 0;

public:

	static const unsigned PALETTE_SIZE = 256;

	Palette();

	~Palette();

	void Update(LPPALETTEENTRY lpEntries);
};

