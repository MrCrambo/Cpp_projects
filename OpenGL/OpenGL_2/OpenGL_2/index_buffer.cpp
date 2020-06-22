#include "index_buffer.h"
#include "renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
    : mCount(count)
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));
    
    __glewGenBuffers(1, &mRendererId);
    __glewBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererId);
    __glewBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    __glewDeleteBuffers(1, &mRendererId);
}

void IndexBuffer::bind() const
{
    __glewBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererId);
}

void IndexBuffer::unbind() const
{
    __glewBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
