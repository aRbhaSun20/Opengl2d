#pragma once

#include "../VertexBuffers/VertexBuff.h"
#include "../VertexBufferLayouts/VertexBufferLayout.h"

class VertexBuff;
class VertexBufferLayout;

class VertexArray
{
private:
    unsigned int m_RenderedID;

public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuff& , const VertexBufferLayout&);

    void Bind() const;
    void Unbind() const;
};
