#pragma once

#include "./VertexArrays/VertexArray.h"
#include "./IndexBuffers/IndexBuffer.h"
#include "./Shaders/ShaderInitialize.h"

class IndexBuff;
class VertexArray;
class ShaderInitialize;

class Renderer
{
public:    
    // Renderer(const IndexBuff&);
    // ~Renderer();
    void Draw(const VertexArray &, const IndexBuff &, const ShaderInitialize &) const;
};



