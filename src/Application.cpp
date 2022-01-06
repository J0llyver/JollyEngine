#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "glm/glm.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "src/Mesh/MeshFactory.h"
#include "src/Object.h"
#include "src/Renderer/Renderer.h"
#include "src/ShaderFactory.h"
#include "src/Texture.h"
#include "src/VertexBuffer.h"

int main(void) {
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit()) return -1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(960, 540, "Canvas", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize glew!" << std::endl;
  }

  {
    glm::vec3 objectPosition(100, 100, 0);
    Object square(MeshPrimitiveType::Square, objectPosition);

    glm::mat4 projectionMatrix = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    glm::mat4 modelViewProjectionMatrix = projectionMatrix * viewMatrix * square.getModelMatrix();

    Texture texture("resc/textures/DwarfFortressMap.png");
    texture.Bind();

    auto renderer = Renderer::getInstance();

    const char *glsl_version = "#version 130";
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    ImGui::StyleColorsDark();

    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
      /* Render here */
      renderer->clear();

      square.translate(objectPosition);
      modelViewProjectionMatrix = projectionMatrix * viewMatrix * square.getModelMatrix();

      // Move to globally accessable shader
      auto shader = ShaderFactory::GetInstance()->GetShader(ShaderType::Basic);

      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();

      {
        ImGui::Begin("Hello, world!");

        ImGui::SliderFloat("Position X", &objectPosition.x, 0.0f, 960.0f);
        ImGui::SliderFloat("Position Y", &objectPosition.y, 0.0f, 540.0f);
        ImGui::ColorEdit3("clear color", (float *)&clear_color);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
        ImGui::End();
      }

      shader->Bind();
      shader->SetUniformMat4f("u_MVP", modelViewProjectionMatrix);
      shader->SetUniform1i("u_Texture", 0);
      shader->Unbind();

      square.render();

      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

      /* Swap front and back buffers */
      glfwSwapBuffers(window);

      /* Poll for and process events */
      glfwPollEvents();
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }

  glfwTerminate();
  return 0;
}
