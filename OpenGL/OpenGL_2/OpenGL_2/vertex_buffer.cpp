#include "vertex_buffer.h"
#include "renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    __glewGenBuffers(1, &mRendererId);
    __glewBindBuffer(GL_ARRAY_BUFFER, mRendererId);
    __glewBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    __glewDeleteBuffers(1, &mRendererId);
}

void VertexBuffer::bind() const
{
    __glewBindBuffer(GL_ARRAY_BUFFER, mRendererId);
}

void VertexBuffer::unbind() const
{
    __glewBindBuffer(GL_ARRAY_BUFFER, 0);
}
