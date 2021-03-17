#include "VertexBuff.h"

VertexBuff ::VertexBuff(const void *data, unsigned int size){
    glGenBuffers(1, &m_RendererId);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuff ::~VertexBuff(){
    glDeleteBuffers(1, &m_RendererId);
}

void VertexBuff ::Bind() const{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
}

void VertexBuff ::UnBind() const{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
