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
          100.0f, 100.0f, 0.0f, 0.0f, //0
          200.0f, 100.0f, 1.0f, 0.0f, //1
          200.0f, 200.0f, 1.0f, 1.0f, //2
          100.0f, 200.0f, 0.0f, 1.0f  //3
      };

      unsigned int indices[6] = {
          // stbi_set_flip_vertically_on_load(1);
          0, 1, 2,
          2, 3, 0};

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
      glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
      glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
      // glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(300, 0, 0));

      // model,view,projection mvp matrix
      // glm::mat4 mvp = proj * view * model;

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

      // imgui context
      ImGui::CreateContext();

      // Setup Platform/Renderer backends
      ImGui_ImplGlfw_InitForOpenGL(hf.window, true);
      ImGui_ImplOpenGL3_Init("#version 330");

      ImGui::StyleColorsDark();

      // Our state
      bool show_demo_window = true;
      bool show_another_window = false;
      ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

      float r = 0.0, increment = 0.01, g = 1.0;
      glm::vec3 translation (300, 0, 0);
     
     
      while (!glfwWindowShouldClose(hf.window))
      {
         // input
         processInput(hf.window);

         // render
         // Set the clear color to a dim black screen

         glClear(GL_COLOR_BUFFER_BIT);
         glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);

         // model,view,projection mvp matrix
         glm::mat4 mvp = proj * view * model;

         // declare the uniforms parameters
         shader.Bind();
         shader.SetUniform4f("u_Color", r, g, 0.9, 1.0);
         shader.SetUniformMat4f("u_MVP", mvp);

         renderer.Draw(va, ib, shader);
         // draw triangle

         ImGui_ImplOpenGL3_NewFrame();
         ImGui_ImplGlfw_NewFrame();
         ImGui::NewFrame();

         // color change animations
         if (r > 1.0)
            increment = -0.01;
         else if (r < 0.0)
            increment = 0.01;

         r += increment;
         g -= increment;

         // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
         {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat3("translation", &translation.x, 0.0f, 960.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
               counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
         }

         ImGui::Render();
         ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

         glfwSwapBuffers(hf.window);
         glfwPollEvents();
      }
   }

   // Cleanup
   ImGui_ImplOpenGL3_Shutdown();
   ImGui_ImplGlfw_Shutdown();
   ImGui::DestroyContext();
   return 0;
}
