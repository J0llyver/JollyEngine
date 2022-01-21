#include "Window.h"

#include "imgui/imgui.h"
#include "src/ComponentManager.h"
#include "src/JollyGame.h"

using namespace gui;

Window::Window(const std::string &name, const uint32_t width, const uint32_t height) {
  this->name = name;
  this->width = width;
  this->height = height;
}

void Window::addComponent(const uint32_t componentId) { idsOfAttachedComponents.push_back(componentId); }

uint32_t Window::createColorPicker(const std::string &label, float* color) {
  const uint32_t newComponentId = ComponentManager::getInstance()->createColorPicker(label, color);
  idsOfAttachedComponents.push_back(newComponentId);
  return newComponentId;
}

uint32_t Window::createFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue,
                                   float* variable) {
  const uint32_t newComponentId =
      ComponentManager::getInstance()->createFloatSlider(label, minimumValue, maximumValue, variable);
  idsOfAttachedComponents.push_back(newComponentId);
  return newComponentId;
}

uint32_t Window::createFrameData() {
  const uint32_t newComponentId = ComponentManager::getInstance()->createFrameData();
  idsOfAttachedComponents.push_back(newComponentId);
  return newComponentId;
}

uint32_t Window::createLog() {
  const uint32_t newComponentId = ComponentManager::getInstance()->createLog();
  idsOfAttachedComponents.push_back(newComponentId);
  return newComponentId;
}

void Window::render() {
  int gameWindowWidth, gameWindowHeight;
  JollyGame::getInstance()->getGameWindowSize(gameWindowWidth, gameWindowHeight);

  ImGui::SetNextWindowPos(ImVec2(gameWindowWidth - width, 0));
  ImGui::SetNextWindowSize(ImVec2(width, height));

  ImGui::Begin(name.c_str());

  const auto componentManager = ComponentManager::getInstance();

  for (const auto componentId : idsOfAttachedComponents) {
    componentManager->renderComponent(componentId);
  }

  ImGui::End();
}
