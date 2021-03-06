#pragma once

#include <string>
#include <StdImage/stb_image.h>
#include "../Renderer/Renderer.h"
#include "index.h"

class Texture
{
private:
    /* data */
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char *m_LocalBuffer;
    int m_Width, m_Height, m_BPP;

public:
    Texture(const std::string &path);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;
    void ReBind(std::string path);

    void LoadImage();

    inline int GetWidth() const { return m_Width; }
    inline int GetHeight() const { return m_Height; }
};
