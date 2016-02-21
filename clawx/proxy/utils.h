#pragma once

#include <GL/glew.h>

#include <cstdio>
#include <string>

static const std::string DUMP_DIR = "Data/";

template<typename T>
inline void Dump(std::string name, const T *ptr) {
	std::string filename = DUMP_DIR + name;
	if (ptr) {
		FILE *f = fopen(filename.c_str(), "wb");
		fwrite(ptr, sizeof(T), 1, f);
		fclose(f);
	}
	else {
		filename += "_nullptr";
		FILE *f = fopen(filename.c_str(), "wb");
		fclose(f);
	}
}

template<typename T>
inline void Load(std::string name, T *ptr) {
	std::string filename = DUMP_DIR + name;
	FILE *f = fopen(filename.c_str(), "rb");
	fread(ptr, sizeof(T), 1, f);
	fclose(f);
}


inline void check_gl_error() {
	GLenum e = glGetError();
	if (e) {
		const char * error = "";
		const char * desc = "";

		switch (e) {
		case GL_INVALID_ENUM: {
			error = "GL_INVALID_ENUM";
			desc = "An unacceptable value is specified for an enumerated argument.The offending command is ignored and has no other side effect than to set the error flag.";
			break;
		}

		case GL_INVALID_VALUE: {
			error = "GL_INVALID_VALUE";
			desc = "A numeric argument is out of range.The offending command is ignored and has no other side effect than to set the error flag.";
			break;
		}

		case GL_INVALID_OPERATION: {
			error = "GL_INVALID_OPERATION";
			desc = "The specified operation is not allowed in the current state.The offending command is ignored and has no other side effect than to set the error flag.";
			break;
		}

		case GL_INVALID_FRAMEBUFFER_OPERATION: {
			error = "GL_INVALID_FRAMEBUFFER_OPERATION";
			desc = "The framebuffer object is not complete.The offending command is ignored and has no other side effect than to set the error flag.";
			break;
		}

		case GL_OUT_OF_MEMORY: {
			error = "GL_OUT_OF_MEMORY";
			desc = "There is not enough memory left to execute the command.The state of the GL is undefined, except for the state of the error flags, after this error is recorded.";
			break;
		}

		case GL_STACK_UNDERFLOW: {
			error = "GL_STACK_UNDERFLOW";
			desc = "An attempt has been made to perform an operation that would cause an internal stack to underflow.";
			break;
		}

		case GL_STACK_OVERFLOW: {
			error = "GL_STACK_OVERFLOW";
			desc = "An attempt has been made to perform an operation that would cause an internal stack to overflow.";
			break;
		}
		}

		MessageBox(0, desc, error, 0);
		std::terminate();
	}
}
