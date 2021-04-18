#include "index.h"

// camera
glm::vec3 cameraPos(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

#define WIDTH 960
#define HEIGHT 560

// timing
float lastFrame = 0.0f;
float field_of_view = 45.0f;

float lastX = WIDTH / 2.0;
float lastY = HEIGHT / 2.0;

bool firstMouse = true;
Timestep timestep;

// view matrix defination
glm::vec3 cameraPosition(0.0f, 0.0f, 3.0f);
PerspectiveCamera p_camera(cameraPosition);

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

int main(int argc, char *argv[])
{
   // glfw initializations
   Initialize Initiate(WIDTH, HEIGHT, "InitGL");

   // Commands Executioner
   ExecuteCommands ExeCommands;

   // Event handler
   Event EventHandler(Initiate.getWindowReference(), p_camera, timestep, WIDTH, HEIGHT);

   glfwSetScrollCallback(Initiate.getWindowReference(), scroll_callback);

   glfwSetInputMode(Initiate.getWindowReference(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);

   // glad initializations
   Initiate.Gladinitialization();

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

      // projection matrix defination
      float AspectRatio = (float)4.0f / (float)3.0f;
      ProjectionMatrix Projection(p_camera.getZoomLevel(), AspectRatio, -1.0f, 100.0f);

      // model matrix defination
      glm::vec3 Translation(-20.0f, 0.0f, 80.0f);
      float Angle = 0.0f;
      glm ::vec3 AxisRotation(1.0f, 1.0f, 0.5f);
      ModelMatrix Model(Translation, Angle, AxisRotation);

      // Mvp matrix defination
      MvpMatrix mvp(Projection, p_camera, Model);

      // Shader class Initiation
      ShaderInitialize shader("../source/Shaders/Basic.shader");
      shader.Bind();

      // background color
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

      Texture texture("/home/arb/Arb/Proj/Opengl/OpenGl-Demo-Pro/images/Asset.png");
      texture.Bind();

      shader.SetUniform1i("u_Texture", 0);

      Renderer renderer;

      ImguiHandle Imhand(Initiate.getWindowReference(), ExeCommands, texture, "#version 330", WIDTH, HEIGHT);
      Imhand.OnAttach();

      while (!glfwWindowShouldClose(Initiate.getWindowReference()))
      {
         float time = (float)glfwGetTime();
         timestep = time - lastFrame;
         lastFrame = time;
         // input
         EventHandler.Event_Keyboard_Callback();
         EventHandler.Event_Mouse_Callback();

         renderer.Clear();
         // render
         // Set the clear color to a dim black screen

         // declare the uniforms parameters

         {
            // // draw the texture
            mvp.setMvpMatrix(Projection, p_camera, Model);
            shader.SetUniformMat4f("u_MVP", mvp.getMvpMatrix());
            renderer.Draw(va, ib, shader);
         }

         Imhand.CreateNewFrame();

         Imhand.DrawElements();
         Imhand.DestroyCreatedFrame();

         glfwSwapBuffers(Initiate.getWindowReference());
         glfwPollEvents();
      }
   }

   return 0;
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
   p_camera.ProcessMouseScroll(yoffset);
}
