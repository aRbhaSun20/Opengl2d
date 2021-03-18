#include "IndexBuffer.h"

IndexBuff ::IndexBuff(const unsigned int *data, unsigned int count)
:m_Count(count)
{
    glGenBuffers(1, &m_RendererId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuff ::~IndexBuff(){
    glDeleteBuffers(1, &m_RendererId);
}

void IndexBuff ::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
}

void IndexBuff ::UnBind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}