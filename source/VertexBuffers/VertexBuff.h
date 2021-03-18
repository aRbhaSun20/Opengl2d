#pragma once
#include <glad/glad.h>

class VertexBuff{
    private:
        unsigned int m_RendererId;
    public:
        VertexBuff(const void *data, unsigned int size);
        ~VertexBuff();

        void Bind() const;
        void UnBind() const;
};