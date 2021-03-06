#include "ShaderInitialize.h"

ShaderInitialize::ShaderInitialize(const std::string &filepath)
    : m_RendererID(0)
{
    ShaderProgramSource source = ParseShader(filepath);
    m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

ShaderInitialize::~ShaderInitialize()
{
    glDeleteProgram(m_RendererID);
}

ShaderProgramSource ShaderInitialize::ParseShader(const std::string &filepath)
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
    return {ss[0].str(), ss[1].str()};
}

unsigned int ShaderInitialize::CompileShader(unsigned int type, const std::string &source)
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

unsigned int ShaderInitialize::CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}

void ShaderInitialize::Bind() const
{
    glUseProgram(m_RendererID);
}

void ShaderInitialize::Unbind() const
{
    glUseProgram(0);
}

void ShaderInitialize::SetUniform1i(const std::string &name, int value)
{
    glUniform1i(GetUniformLocation(name), value);
}

void ShaderInitialize::SetUniform1f(const std::string &name, float value)
{
    glUniform1f(GetUniformLocation(name), value);
}

void ShaderInitialize::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3)
{
    glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void ShaderInitialize::SetUniformMat4f(const std::string &name, const glm::mat4 &matrix)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderInitialize::SetUniform3f(const std::string &name, float v0, float v1, float v2)
{
    glUniform3f(GetUniformLocation(name), v0, v1, v2);
}

int ShaderInitialize::GetUniformLocation(const std::string &name)
{

    if (m_Uniform_locationCache.find(name) != m_Uniform_locationCache.end())
        return m_Uniform_locationCache[name];

    int location = glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1)
        std::cout << "Warning: uniform " << name << " doesn't exist!" << std::endl;

    m_Uniform_locationCache[name] = location;
    return location;
}
