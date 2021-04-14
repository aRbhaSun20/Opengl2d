#include "index.h"

// camera
glm::vec3 cameraPos(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

const int WIDTH = 960;
const int HEIGHT = 560;

float speed = 10.0f;
float yaw = -90.0f;
float pitch = 0.0f;
// timing

// float deltaTime = 0.0f;
float lastFrame = 0.0f;
float field_of_view = 45.0f;

float lastX = WIDTH / 2.0;
float lastY = HEIGHT / 2.0;

bool firstMouse = true;
Timestep timestep;

// view matrix defination
glm::vec3 cameraPosition(0.0f, 0.0f, 3.0f);
PerspectiveCamera p_camera(cameraPosition);

static void error_callback(int error, const char *description)
{
   fprintf(stderr, "Error: %s\n", description);
}

void framebuffer_size(GLFWwindow *window, int width, int height)
{
   glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

int main(int argc, char *argv[])
{
   // initializations
   glfwSetErrorCallback(error_callback);

   Initialize hf(WIDTH, HEIGHT, "InitGL");
   glfwMakeContextCurrent(hf.getWindowReference());

   glfwSetFramebufferSizeCallback(hf.getWindowReference(), framebuffer_size);

   glfwSetKeyCallback(hf.getWindowReference(), key_callback);
   glfwSetCursorPosCallback(hf.getWindowReference(), mouse_callback);
   glfwSetScrollCallback(hf.getWindowReference(), scroll_callback);

   glfwSetInputMode(hf.getWindowReference(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);

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

      Texture texture("../images/Asset.png");
      texture.Bind();

      shader.SetUniform1i("u_Texture", 0);

      va.Unbind();
      vb.UnBind();
      ib.UnBind();

      Renderer renderer;

      ImguiHandle Imhand(hf.getWindowReference(), "#version 330");

      glm::vec3 translationA(480, 200, 0);
      glm::vec3 translationB(600, 100, 0);

      while (!glfwWindowShouldClose(hf.getWindowReference()))
      {
         float time = (float)glfwGetTime();
         timestep = time - lastFrame;
         lastFrame = time;
         // input
         processInput(hf.getWindowReference());

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

         //  Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
         Imhand.DrawElements(&translationA.x, &translationB.x, 0, 960, 0, 960);
         Imhand.RenderElements();

         glfwSwapBuffers(hf.getWindowReference());
         glfwPollEvents();
      }
   }

   return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
   float sensitivity = 0.15f;

   if (firstMouse)
   {
      lastX = xpos;
      lastY = ypos;
      firstMouse = false;
   }

   float xOffset = (xpos - lastX);
   float yOffset = (lastY - ypos);

   lastX = xpos;
   lastY = ypos;

   p_camera.ProcessMouseMovement(xOffset, yOffset);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{

   p_camera.ProcessMouseScroll(yoffset);
}

void processInput(GLFWwindow *window)
{
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);

   // float cameraSpeed = speed * timestep.GetSeconds();

   if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
   {
      // cameraPos += cameraSpeed * cameraFront;
      p_camera.ProcessKeyboard(Camera_Movement::FORWARD, timestep.GetSeconds());
   }
   if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
   {
      // cameraPos -= cameraSpeed * cameraFront;
      p_camera.ProcessKeyboard(Camera_Movement::BACKWARD, timestep.GetSeconds());
   }
   if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
   {
      // cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
      p_camera.ProcessKeyboard(Camera_Movement::LEFT, timestep.GetSeconds());
   }
   if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
   {
      // cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
      p_camera.ProcessKeyboard(Camera_Movement::RIGHT, timestep.GetSeconds());
   }
   if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
   {
      p_camera.ProcessKeyboard(Camera_Movement::UP, timestep.GetSeconds());
   }

   if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
   {
      p_camera.ProcessKeyboard(Camera_Movement::DOWN, timestep.GetSeconds());
   }
}
