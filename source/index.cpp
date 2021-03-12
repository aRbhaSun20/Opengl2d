#include <stdio.h>
#include "index.h"

#include <fstream>
#include <sstream>

struct ShaderProgramSource
{
   std::string VertexSource;
   std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string &filepath)
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

static void error_callback(int error, const char *description)
{
   fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void framebuffer_size(GLFWwindow *window, int width, int height)
{
   glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);
}

static int CompileShader(unsigned int type, const std::string &source)
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

static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
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

int main(int argc, char *argv[])
{
   // initializations
   glfwSetErrorCallback(error_callback);

   helperFunction hf(800, 800, "InitGL");

   glfwSetKeyCallback(hf.window, key_callback);

   glfwMakeContextCurrent(hf.window);

   glfwSetFramebufferSizeCallback(hf.window, framebuffer_size);

   hf.Gladinitialization();

   // start the declarations from here

   // // vertex shader
   // const char *vertexShaderSource = "#version 330 core\n"
   //                                  "layout (location = 0) in vec3 aPos;\n"
   //                                  "void main()\n"
   //                                  "{\n"
   //                                  "  gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
   //                                  "}\0";

   // // fragment shader
   // const char *fragmentShaderSource = "#version 330 core\n"
   //                                    "out vec4 FragColor;\n"
   //                                    "void main()\n"
   //                                    "{\n"
   //                                    "   FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
   //                                    "}\n\0";

   ShaderProgramSource source = ParseShader("../source/Shaders/Basic.shader");

   int shaderProgram = CreateShader(source.VertexSource, source.FragmentSource);
   glUseProgram(shaderProgram);

   float vertices[9] = {
       -0.5f, -0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,
       0.0f, 0.5f, 0.0f};

   unsigned int buffer, vertexArray;
   glGenVertexArrays(1, &vertexArray);
   glGenBuffers(1, &buffer);

   glBindVertexArray(vertexArray);

   glBindBuffer(GL_ARRAY_BUFFER, buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
   glEnableVertexAttribArray(0);

   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glBindVertexArray(vertexArray);

   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

   while (!glfwWindowShouldClose(hf.window))
   {
      // input
      processInput(hf.window);

      // render
      // Set the clear color to a dim black screen

      glClear(GL_COLOR_BUFFER_BIT);

      // draw triangle
      glDrawArrays(GL_TRIANGLES, 0, 3);

      glfwSwapBuffers(hf.window);
      glfwPollEvents();
   }

   glDeleteVertexArrays(1, &vertexArray);
   glDeleteBuffers(1, &buffer);
   glDeleteProgram(shaderProgram);

   glfwDestroyWindow(hf.window);
   glfwTerminate();

   return 0;
}
