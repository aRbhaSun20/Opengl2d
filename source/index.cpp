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

   Initialize hf(800, 800, "InitGL");

   glfwSetKeyCallback(hf.window, key_callback);

   glfwMakeContextCurrent(hf.window);

   glfwSetFramebufferSizeCallback(hf.window, framebuffer_size);

   hf.Gladinitialization();

   // start the declarations from here
   {
      // vertices of a geometrical diagram
      float vertices[12] = {
          -0.5f, -0.5f, 0.0f,
          0.5f, -0.5f, 0.0f,
          0.5f, 0.5f, 0.0f,
          -0.5f, 0.5f, 0.0f};

      unsigned int indices[6] = {
          0, 1, 2,
          2, 3, 0};

      // vertex array object
      VertexArray va;
      VertexBuff vb(vertices, 4 * 3 * sizeof(float));

      VertexBufferLayout layout;
      layout.Push<float>(3);
      va.AddBuffer(vb, layout);

      // index buffer object
      IndexBuff ib(indices, 6);
      unsigned int ibo;

      // shader program initiation
      ShaderInitialize shader("../source/Shaders/Basic.shader");
      shader.Bind();

      // background color
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

      va.Unbind();
      vb.UnBind();
      ib.UnBind();

      Renderer renderer;
      float r = 0.0, increment = 0.01, g = 1.0;

      while (!glfwWindowShouldClose(hf.window))
      {
         // input
         processInput(hf.window);

         // render
         // Set the clear color to a dim black screen

         glClear(GL_COLOR_BUFFER_BIT);

         // declare the uniforms parameters
         shader.SetUniform4f("u_Color", r, g, 0.9, 1.0);

         renderer.Draw(va, ib, shader);
         // draw triangle

         // color change animations
         if (r > 1.0)
            increment = -0.01;
         else if (r < 0.0)
            increment = 0.01;

         r += increment;
         g -= increment;

         glfwSwapBuffers(hf.window);
         glfwPollEvents();
      }
   }

   return 0;
}
