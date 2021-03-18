#include "Renderer.h"

void Renderer::Draw(const VertexArray &va, const IndexBuff &ib, const ShaderInitialize &shader) const
{
    shader.Bind();
    // shader.SetUniform4f("u_Color", r, g, 0.9, 1.0);
    va.Bind();

    ib.Bind();

    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}