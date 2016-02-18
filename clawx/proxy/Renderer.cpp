#include "Renderer.h"

Renderer::Renderer()
{
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

	palette_texture_buffer[0] = 0;
	palette_texture_buffer[1] = 0;
	palette_texture_buffer[2] = 0;
	palette_texture_buffer[3] = 0;

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
