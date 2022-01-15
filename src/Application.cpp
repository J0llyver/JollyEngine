// This needs to be included first because glew needs to be included before glm
#include "GuiManager.h"
#include "JollyGame.h"
#include "Object.h"
#include "Renderer.h"
#include "Texture.h"
#include "glm/glm.hpp"
#include "gui/ComponentManager.h"

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
  imguiWindow->createFloatSlider("Position X", 0.0f, 540.0f, &objectPosition.x);
  imguiWindow->createFloatSlider("Position Y", 0.0f, 540.0f, &objectPosition.y);
  imguiWindow->createColorPicker("clear color", (float*)&clear_color);
  imguiWindow->createFrameData();

  auto logId = imguiWindow->createLog();
  auto log = gui::ComponentManager::getInstance()->getLog(logId);
  log->log("Patrick");
  log->log("Spongebob");

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
