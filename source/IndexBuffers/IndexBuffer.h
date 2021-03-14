#pragma once
#include "../index.h"

class IndexBuffer
{
private:
    unsigned int m_RendererId;
    unsigned int m_Count;

public:
    IndexBuffer(const unsigned *data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void UnBind() const;

    inline unsigned int GetCount() const{return m_Count;}
};