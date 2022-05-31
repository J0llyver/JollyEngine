#include "CameraManager.h"
#include "ComponentManager.h"
#include "GuiManager.h"
#include "JollyGame.h"
#include "Renderer.h"
#include "Scenery/Prop.h"
#include "Texture.h"
#include "glm/glm.hpp"

#include <iostream>

int main() {
  auto game = JollyGame::getInstance();

  auto renderer = Renderer::getInstance();

  CameraManager::getInstance()->createCamera("main");

  glm::vec3 objectPosition(0, 0, 0);
  Prop square(MeshPrimitiveType::Square, objectPosition);
  square.scale(10.0f);

  Prop square2(MeshPrimitiveType::Square, objectPosition);

  // ToDo: Create Texture Manager
  Texture texture("resc/textures/DwarfFortressMap.png");
  texture.Bind();

  auto guiManager = GuiManager::getInstance();

  int windowWidth, windowHeight;
  game->getGameWindowSize(windowWidth, windowHeight);

  auto imguiWindow = guiManager->createWindow("Patrick", 400, 250);
  imguiWindow->createFloatSlider("Position X", -1.0f, 1.0f, &objectPosition.x);
  imguiWindow->createFloatSlider("Position Y", -1.0f, 1.0f, &objectPosition.y);

  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  imguiWindow->createColorPicker("clear color", (float*)&clear_color);

  imguiWindow->createFrameData();

  auto logId = imguiWindow->createLog();
  auto log = gui::ComponentManager::getInstance()->getLog(logId);
  log->log("Patrick");
  log->log("Spongebob");

  while (!game->windowShouldClose()) {
    renderer->clear();

    square.translate(objectPosition);
    square.pitch(-0.01f);
    square.yaw(-0.01f);
    square.roll(-0.01f);
    square2.render();
    square.render();

    guiManager->renderGui();

    game->swapBuffers();
    game->pollEvents();
  }

  return 0;
}
