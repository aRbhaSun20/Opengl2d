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
    void Clear();
    void Draw(const VertexArray &, const IndexBuff &, const ShaderInitialize &) const;
};



