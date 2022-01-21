#include <iostream>

#include "CameraManager.h"
#include "ComponentManager.h"
#include "GuiManager.h"
#include "JollyGame.h"
#include "Object.h"
#include "Renderer.h"
#include "Texture.h"
#include "glm/glm.hpp"

int main() {
  auto game = JollyGame::getInstance();

  // Our state
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  auto renderer = Renderer::getInstance();

  CameraManager::getInstance()->createCamera("main");
  const auto camera = CameraManager::getInstance()->getCamera("main");

  const auto cameraProjectionMatrix = camera->getProjectionMatrix();

  glm::vec3 objectPosition(0, 0, 0);
  Object square(MeshPrimitiveType::Square, objectPosition);
  square.scale(10.0f);

  Object square2(MeshPrimitiveType::Square, objectPosition);

  // ToDo: Create Texture Manager
  Texture texture("resc/textures/DwarfFortressMap.png");
  texture.Bind();

  auto guiManager = GuiManager::getInstance();

  int windowWidth, windowHeight;
  game->getGameWindowSize(windowWidth, windowHeight);

  auto imguiWindow = guiManager->createWindow("Patrick", 400, 250);
  imguiWindow->createFloatSlider("Position X", 0.0f, windowWidth, &objectPosition.x);
  imguiWindow->createFloatSlider("Position Y", 0.0f, windowHeight, &objectPosition.y);
  imguiWindow->createColorPicker("clear color", (float*)&clear_color);
  imguiWindow->createFrameData();

  auto logId = imguiWindow->createLog();
  auto log = gui::ComponentManager::getInstance()->getLog(logId);
  log->log("Patrick");
  log->log("Spongebob");

  while (!game->windowShouldClose()) {
    renderer->clear();

    square.translate(objectPosition);
    square.render();
    square2.render();

    guiManager->renderGui();

    game->swapBuffers();
    game->pollEvents();
  }

  return 0;
}
