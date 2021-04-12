#include "index.h"

// camera
glm::vec3 cameraPos(0.0f, 0.0f, 0.3f);
glm::vec3 cameraFront(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

const int WIDTH = 960;
const int HEIGHT = 560;

float speed = 10.0f;
float yaw = -90.0f;
float pitch = 0.0f;
// timing

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float field_of_view = 45.0f;

float lastX = WIDTH / 2.0;
float lastY = HEIGHT / 2.0;

bool firstMouse = true;


static void error_callback(int error, const char *description)
{
   fprintf(stderr, "Error: %s\n", description);
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

   xOffset *= sensitivity;
   yOffset *= sensitivity;

   yaw += xOffset;
   pitch += yOffset;

   // Constraints for pitch angle
   if (pitch > 89.0f)
      pitch = 89.0f;
   if (pitch < -89.0f)
      pitch = -89.0f;

   glm::vec3 front;
   front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
   front.y = sin(glm::radians(pitch));
   front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
   cameraFront = glm::normalize(front);

   // std::cout << "Mouse Cursor at (" << xpos << ", " << ypos << ")" << std::endl;
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
   if (field_of_view >= 1.0f && field_of_view <= 45.0f)
      field_of_view += yoffset;
   if (field_of_view <= 1.0f)
      field_of_view = 1.0f;
   if (field_of_view >= 45.0f)
      field_of_view = 45.0f;
}

void framebuffer_size(GLFWwindow *window, int width, int height)
{
   glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, true);

   float cameraSpeed = 5.0f * deltaTime;
   if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
   {
      cameraPos += cameraSpeed * cameraFront;
   }
   if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
   {
      cameraPos -= cameraSpeed * cameraFront;
   }
   if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
   {
      cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
   }
   if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
   {
      cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
   }
}

int main(int argc, char *argv[])
{
   // initializations
   glfwSetErrorCallback(error_callback);

   Initialize hf(WIDTH, HEIGHT, "InitGL");

   glfwSetKeyCallback(hf.getWindowReference(), key_callback);
   glfwSetCursorPosCallback(hf.getWindowReference(), mouse_callback);
   glfwSetScrollCallback(hf.getWindowReference(), scroll_callback);

   glfwMakeContextCurrent(hf.getWindowReference());

   glfwSetFramebufferSizeCallback(hf.getWindowReference(), framebuffer_size);

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

      // camera class
      float multiplier = 1.0f;
      OrthographicCamera m_Camera(-1.6f * multiplier, 1.6f * multiplier, -0.9f * multiplier, 0.9f * multiplier);

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
      // glm::vec3 cameraView;
      glm::vec3 translationB(600, 100, 0);

      while (!glfwWindowShouldClose(hf.getWindowReference()))
      {
         float currentFrame = glfwGetTime();
         deltaTime = currentFrame - lastFrame;
         lastFrame = currentFrame;
         // input
         processInput(hf.getWindowReference());

         renderer.Clear();

         m_Camera.reorganizeCamera(-1.6f * multiplier, 1.6f * multiplier, -0.9f * multiplier, 0.9f * multiplier);
         // render
         // Set the clear color to a dim black screen

         // declare the uniforms parameters

         {
            // model,view,projection mvp matrix
            Mvp.MvpHandleCamera(cameraPos, cameraFront, cameraUp);
            Mvp.MvpHandleModel(1.0f, translationA);
            shader.SetUniformMat4f("u_MVP", Mvp.mvp());
            // draw the texture
            renderer.Draw(va, ib, shader);
         }

         {
            // model,view,projection mvp matrix
            m_Camera.MvpHandleModel(translationB);
            shader.SetUniformMat4f("u_MVP", m_Camera.GetViewProjectionMatrix());
            // draw the texture
            renderer.Draw(va, ib, shader);
         }

         Imhand.CreateNewFrame();

         //  Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
         Imhand.DrawElements(&translationA.x, &translationB.x, &speed, &multiplier, 0, 960, 0, 960);
         Imhand.RenderElements();

         glfwSwapBuffers(hf.getWindowReference());
         glfwPollEvents();
      }
   }

   return 0;
}
