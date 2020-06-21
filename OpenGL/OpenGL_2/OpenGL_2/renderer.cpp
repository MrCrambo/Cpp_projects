#include "renderer.h"

#include <iostream>

void GlClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, const char* line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}
