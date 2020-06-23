#pragma once

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    bool normalized;
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> mElements;
public:
    VertexBufferLayout();
    ~VertexBufferLayout();
    
    template <typename T>
    void push(unsigned int count)
    {
        static_assert(true, "Failed");
    }
    
    template <>
    void push<float>(unsigned int count)
    {
        mElements.push_back({GL_FLOAT, count, false});
    }
    
    template <>
    void push<unsigned int>(unsigned int count)
    {
        mElements.push_back({GL_UNSIGNED_INT, count, false});
    }
};
