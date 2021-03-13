#pragma once 
#include <fstream>
#include <sstream>

#include "index.h"
struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class ShaderInitialize
{
private:
    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };
    std::string line;
    ShaderType type = ShaderType::NONE;
    struct ShaderProgramSource
    {
        std::string VertexSource;
        std::string FragmentSource;
    };
    /* data */
public:
    std::stringstream ss[2];

    ShaderInitialize(const std::string &filepath);

    int CompileShader(unsigned int type, const std::string &source);

    unsigned int CreateShader();
};
