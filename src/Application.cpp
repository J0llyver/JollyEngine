// This needs to be included first because glew needs to be included before glm
#include "JollyGame.h"

#include "glm/glm.hpp"
#include "GuiManager.h"
#include "Object.h"
#include "Renderer.h"
#include "Texture.h"

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

  auto guiManager = GuiManager::getInstance();

  auto imguiWindow = guiManager->createWindow("Patrick", 400, 250);
  imguiWindow->addFloatSlider("Position X", 0.0f, 540.0f, &objectPosition.x);
  imguiWindow->addFloatSlider("Position Y", 0.0f, 540.0f, &objectPosition.y);
  imguiWindow->addColorPicker("clear color", (float*)&clear_color);
  imguiWindow->addFrameData();

  /* Loop until the user closes the window */
  while (!game->windowShouldClose()) {
    /* Render here */
    renderer->clear();

    guiManager->renderGui();

    square.translate(objectPosition);
    square.render();
    square2.render();

    game->swapBuffers();
    game->pollEvents();
  }

  return 0;
}
