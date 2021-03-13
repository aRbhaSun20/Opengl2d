#include "ShaderInitialize.h"

ShaderInitialize::ShaderInitialize(const std::string &filepath)
{
    std::ifstream stream(filepath);

    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }
    std::cout << ss[0].str() << std::endl;
    // return {ss[0].str(), ss[1].str()};
}

int ShaderInitialize::CompileShader(unsigned int type, const std::string &source)
{
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);

        char *infoLog = (char *)alloca(len * sizeof(char));
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "Vertex" : " Fragment") << "Shader!" << std::endl;
        Log(infoLog);

        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int ShaderInitialize::CreateShader()
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, ss[0].str());
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, ss[1].str());

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}
