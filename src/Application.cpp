#include "JollyGame.h"
#include "Object.h"
#include "Renderer.h"
#include "Texture.h"
#include "glm/glm.hpp"
#include "gui/Window.h"

int main() {
  auto game = JollyGame::getInstance();

  // Our state
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  auto renderer = Renderer::getInstance();

  glm::vec3 objectPosition(100, 100, 0);
  Object square(MeshPrimitiveType::Square, objectPosition);

  Object square2(MeshPrimitiveType::Square, objectPosition);

  // ToDo: Create Texture Manager
  Texture texture("resc/textures/DwarfFortressMap.png");
  texture.Bind();

  gui::Window imguiWindow("Patrick", 400, 250);
  imguiWindow.addFloatSlider("Position X", 0.0f, 540.0f, &objectPosition.x);
  imguiWindow.addFloatSlider("Position Y", 0.0f, 540.0f, &objectPosition.y);
  imguiWindow.addColorPicker("clear color", (float*)&clear_color);
  imguiWindow.addFrameData();

  /* Loop until the user closes the window */
  while (!game->windowShouldClose()) {
    /* Render here */
    renderer->clear();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    imguiWindow.render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    square.translate(objectPosition);
    square.render();
    square2.render();

    game->swapBuffers();
    game->pollEvents();
  }

  return 0;
}
