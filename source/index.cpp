#include <stdio.h>
#include "index.h"

ShaderProgramSource ParseShader(const std::string &filepath)
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

int CompileShader(unsigned int type, const std::string &source)
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

unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
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

   Initialize hf(800, 800, "InitGL");

   glfwSetKeyCallback(hf.window, key_callback);

   glfwMakeContextCurrent(hf.window);

   glfwSetFramebufferSizeCallback(hf.window, framebuffer_size);

   hf.Gladinitialization();

   // start the declarations from here

   // vertices of a geometrical diagram
   float vertices[18] = {
       -0.5f, -0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,
       0.5f, 0.5f, 0.0f,
       -0.5f, 0.5f, 0.0f
   };

   unsigned int indices[6] = {
       0, 1, 2,
       2, 3, 0
   };

   // buffer normal
   unsigned int buffer;
   glGenBuffers(1, &buffer);
   glBindBuffer(GL_ARRAY_BUFFER, buffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

   // index buffer object
   unsigned int ibo;
   glGenBuffers(1, &ibo);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   // shader program initiation
   // ShaderInitialize newShader("../source/Shaders/Basic.shader");
   ShaderProgramSource source = ParseShader("../source/Shaders/Basic.shader");

   // int shaderProgram = newShader.CreateShader();
   int shaderProgram = CreateShader(source.VertexSource, source.FragmentSource);
   glUseProgram(shaderProgram);

   // Uniforms
   int location = glGetUniformLocation(shaderProgram, "u_Color");
   glUniform4f(location, 1.0, 0.5, 0.9, 1.0);

   // background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

   float r = 0.0,increment = 0.01;

   while (!glfwWindowShouldClose(hf.window))
   {
      // input
      processInput(hf.window);

      // render
      // Set the clear color to a dim black screen

      glClear(GL_COLOR_BUFFER_BIT);

      // draw triangle
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
      // declare the uniforms parameters
      glUniform4f(location, r, 0.5, 0.9, 1.0);
   
   // color change animations
      if(r > 1.0)
         increment = -0.01;
      else if (r < 0.0)
         increment = 0.01;

      r += increment;

      glfwSwapBuffers(hf.window);
      glfwPollEvents();
   }

   glDeleteBuffers(1, &buffer);
   glDeleteProgram(shaderProgram);

   glfwDestroyWindow(hf.window);
   glfwTerminate();

   return 0;
}
