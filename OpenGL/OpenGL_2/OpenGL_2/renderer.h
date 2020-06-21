#pragma once

#include <GL/glew.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GlClearError();\
x;\
ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GlClearError();

bool GLLogCall(const char* function, const char* file, const char* line);
