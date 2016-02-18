#pragma once

#include "Surface.h"

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
	struct Surface {
		int width = 0;
		int height = 0;

		GLuint fbo = 0;

		GLuint vao;
		GLuint texture;

		std::vector<byte> texture_buffer;
	};

	static const unsigned PALETTE_SIZE = 256;

	Renderer(HWND hwnd);

	~Renderer();

	Surface CreateSurface(int width, int height, bool fb);

	void CreateFramebuffer(Surface *surface) {
		if (surface->fbo == 0) {
			glGenFramebuffers(1, &surface->fbo);
			glBindFramebuffer(GL_FRAMEBUFFER, surface->fbo);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, surface->texture, 0);
		}
	}

	void DownloadSurfaceBuffer(Surface *surface) {
		//if (surface->fbo) {
			glBindTexture(GL_TEXTURE_2D, surface->texture);
			glGetTexImage(GL_TEXTURE_2D, 0, GL_RED, GL_UNSIGNED_BYTE, surface->texture_buffer.data());
		//}
	}

	void UploadSurfaceBuffer(Surface *surface) {
		glBindTexture(GL_TEXTURE_2D, surface->texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, surface->width, surface->height, 0, GL_RED, GL_UNSIGNED_BYTE, surface->texture_buffer.data());

	}

	void SetPalette(LPPALETTEENTRY lpEntries);

	void Render(int x, int y, Surface *a, Surface *b) {
		CreateFramebuffer(a);

		GLuint fbo = a->fbo;
		GLuint program = surface_program;
		auto &surface = *b;

		glUseProgram(program);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		assert(!glGetError());

		glm::mat4 pos;
		pos = glm::translate(pos, { x, y, 0 });

		auto uniPos = glGetUniformLocation(program, "pos");
		if (uniPos >= 0)
			glUniform2f(uniPos, x, y);

		assert(!glGetError());

		glm::mat4 trans;

		if (fbo == 0) {
			trans = glm::scale(trans, { 1, -1, 1 });
		}

		trans = glm::translate(trans, { -1, -1, 0 });

		float sx = 2 / 640.f;
		float sy = 2 / 480.f;

		trans = glm::scale(trans, { sx, sy, 1 });

		GLint uniTrans = glGetUniformLocation(program, "trans");
		if (uniTrans >= 0)
			glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

		assert(!glGetError());

		glBindVertexArray(surface.vao);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, surface.texture);

		assert(!glGetError());

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_1D, palette_texture);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		assert(!glGetError());
	}

	void RenderToScreen(Surface *b) {
		GLuint fbo = 0;
		GLuint program = frontbuffer_program;
		auto &surface = *b;
		int x = 0;
		int y = 0;

		glUseProgram(program);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		assert(!glGetError());

		glm::mat4 pos;
		pos = glm::translate(pos, { x, y, 0 });

		auto uniPos = glGetUniformLocation(program, "pos");
		if (uniPos >= 0)
			glUniform2f(uniPos, x, y);

		assert(!glGetError());

		glm::mat4 trans;

		if (fbo == 0) {
			trans = glm::scale(trans, { 1, -1, 1 });
		}

		trans = glm::translate(trans, { -1, -1, 0 });

		float sx = 2 / 640.f;
		float sy = 2 / 480.f;

		trans = glm::scale(trans, { sx, sy, 1 });

		GLint uniTrans = glGetUniformLocation(program, "trans");
		if (uniTrans >= 0)
			glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(trans));

		assert(!glGetError());

		glBindVertexArray(surface.vao);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, surface.texture);

		assert(!glGetError());

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_1D, palette_texture);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		assert(!glGetError());
	}
};

