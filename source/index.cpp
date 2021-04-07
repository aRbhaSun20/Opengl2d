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

   Initialize hf(960, 540, "InitGL");

   glfwSetKeyCallback(hf.window, key_callback);

   glfwMakeContextCurrent(hf.window);

   glfwSetFramebufferSizeCallback(hf.window, framebuffer_size);

   hf.Gladinitialization();

   // start the declarations from here
   {
      // vertices of a geometrical diagram
      float vertices[] = {
          -50.0f, -50.0f, 0.0f, 0.0f, //0
          50.0f, -50.0f, 1.0f, 0.0f,  //1
          50.0f, 50.0f, 1.0f, 1.0f,   //2
          -50.0f, 50.0f, 0.0f, 1.0f   //3
      };

      unsigned int indices[6] = {
          0, 1, 2, //1st triangle
          2, 3, 0  //2nd triangle
      };

      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

      // vertex array object
      VertexArray va;
      VertexBuff vb(vertices, 4 * 4 * sizeof(float));

      VertexBufferLayout layout;
      layout.Push<float>(2);
      layout.Push<float>(2);
      va.AddBuffer(vb, layout);

      // index buffer object
      IndexBuff ib(indices, 6);

      // projection,view,model matrix defination
      MvpHandle Mvp;
      
      Mvp.MvpHandleProjection(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
      glm::vec3 transformation(0, 0, 0);
      Mvp.MvpHandleView(1.0f, transformation);


      // shader program initiation
      ShaderInitialize shader("../source/Shaders/Basic.shader");
      shader.Bind();

      // shader.SetUniformMat4f("u_MVP", mvp);

      // background color
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

      Texture texture("../images/Asset.png");
      texture.Bind();

      shader.SetUniform1i("u_Texture", 0);

      va.Unbind();
      vb.UnBind();
      ib.UnBind();

      Renderer renderer;

      ImguiHandle Imhand(hf.window, "#version 330");

      glm::vec3 translationA(300, 0, 0);
      glm::vec3 translationB(400, 0, 0);

      while (!glfwWindowShouldClose(hf.window))
      {
         // input
         processInput(hf.window);

         renderer.Clear();

         // render
         // Set the clear color to a dim black screen

         // declare the uniforms parameters

         { 
            // model,view,projection mvp matrix
            Mvp.MvpHandleModel(1.0f, translationA);
            shader.SetUniformMat4f("u_MVP", Mvp.mvp());
            // draw the texture
            renderer.Draw(va, ib, shader);
         }

         { 
            // model,view,projection mvp matrix
            Mvp.MvpHandleModel(1.0f, translationB);
            shader.SetUniformMat4f("u_MVP", Mvp.mvp());
            // draw the texture
            renderer.Draw(va, ib, shader);
         }

         Imhand.CreateNewFrame();

         //  Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
         Imhand.DrawElements(&translationA.x, &translationB.x, 0, 960, 0, 960);

         Imhand.RenderElements();

         glfwSwapBuffers(hf.window);
         glfwPollEvents();
      }
   }

   return 0;
}
