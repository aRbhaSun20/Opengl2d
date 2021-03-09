#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "index.h"

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



int main(int argc, char *argv[])
{
   // initializations
   glfwSetErrorCallback(error_callback);

   if (!glfwInit())
      Log("Failure to initialize glfww");

   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

   GLFWwindow *window = glfwCreateWindow(800, 600, "InitGL", nullptr, nullptr);

   if (!window)
   {
      glfwTerminate();
      Log("Window cration failure");
      return -1;
   }

   glfwSetKeyCallback(window, key_callback);

   glfwMakeContextCurrent(window);

   glfwSetFramebufferSizeCallback(window, framebuffer_size);

   if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
   {
      Log("Failure to initialize glad");
      return -1;
   }
   // start the declarations from here

   // vertedx shader
   const char *vertexShaderSource = "#version 330 core\n"
                                    "layout (location = 0) in vec3 aPos;\n"
                                    "void main()\n"
                                    "{\n"
                                    "  gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
                                    "}\0";

   unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
   glCompileShader(vertexShader);

   int success;
   char infoLog[512];

   glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
   if (!success)
   {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      Log("vertex failure");
   }

   // fragment shader
   const char *fragmentShaderSource = "#version 330 core\n"
                                      "out vec4 FragColor;\n"
                                      "void main()\n"
                                      "{\n"
                                      "   FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
                                      "}\n\0";

   unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
   glCompileShader(fragmentShader);

   glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
   if (!success)
   {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      Log("fragment failure");
   }

   // link shader program
   unsigned int shaderProgram = glCreateProgram();
   glAttachShader(shaderProgram, vertexShader);
   glAttachShader(shaderProgram, fragmentShader);
   glLinkProgram(shaderProgram);

   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
   if (!success)
   {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      Log("linking shader failure");
   }
   // shader activation

   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);

   // glUseProgram(shaderProgram);

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
   glBindVertexArray(0);

   while (!glfwWindowShouldClose(window))
   {
      // input
      processInput(window);

      // render
      // Set the clear color to a dim black screen
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      // draw triangle
      glUseProgram(shaderProgram);
      glBindVertexArray(vertexArray);
      glDrawArrays(GL_TRIANGLES, 0, 3);

      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   glDeleteVertexArrays(1, &vertexArray);
   glDeleteBuffers(1, &buffer);
   glDeleteProgram(shaderProgram);

   glfwDestroyWindow(window);
   glfwTerminate();

   return 0;
}
