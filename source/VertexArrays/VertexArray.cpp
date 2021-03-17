#include "VertexArray.h"

VertexArray::VertexArray(/* args */)
{
    glGenVertexArrays(1, &m_RenderedID);
    glBindVertexArray(m_RenderedID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RenderedID);
}

void VertexArray::AddBuffer(const VertexBuff& vb, const VertexBufferLayout& layout){
    Bind();
    vb.Bind();
    const auto &elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size();i++)
    {
        const auto &element = elements[i];
        glEnableVertexAttribArray(i);
        // links the buffer to vao
        glVertexAttribPointer(i, element.count, element.type, 
        element.normalized, layout.GetStride(), (void *)(uint64_t)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const {
    glBindVertexArray(m_RenderedID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}