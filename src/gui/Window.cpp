#include "Window.h"

#include "ComponentManager.h"

#include <GLFW/glfw3.h>

void gui::Window::addFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue, float *variable) {
  componentIds.insert(gui::ComponentManager::getInstance()->createFloatSlider(label, minimumValue, maximumValue, variable));
}

void gui::Window::addColorEditor(const std::string &label, float *color) { 
  componentIds.insert(gui::ComponentManager::getInstance()->createColorPicker(label, color));
}

void gui::Window::addFrameData() {
  componentIds.insert(gui::ComponentManager::getInstance()->getFrameData());
}

void gui::Window::render() {
  auto componentManager = gui::ComponentManager::getInstance();

  int windowWidth, windowHeight;
  glfwGetWindowSize(window, &windowWidth, &windowHeight);

  ImGui::SetNextWindowPos(ImVec2(windowWidth - width, 0));
  ImGui::SetNextWindowSize(ImVec2(width, height));

  ImGui::Begin(name);
  for (const auto id : componentIds) {
    componentManager->getComponent(id)->render();
  }
  ImGui::End();
}

