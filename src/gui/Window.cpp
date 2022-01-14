#include "Window.h"

#include "imgui/imgui.h"
#include "src/JollyGame.h"

using namespace gui;

Window::Window(const std::string &name, const uint32_t width, const uint32_t height) {
  this->name = name;
  this->width = width;
  this->height = height;
}

std::shared_ptr<FloatSlider> Window::addFloatSlider(const std::string &label, const float &minimumValue,
                                                    const float &maximumValue, float* variable) {
  components.insert(
      std::make_pair(nextComponentId, std::make_shared<FloatSlider>(label, minimumValue, maximumValue, variable)));
  ++nextComponentId;

  return static_pointer_cast<FloatSlider>(components[nextComponentId - 1]);
}

std::shared_ptr<ColorPicker> Window::addColorPicker(const std::string &label, float* color) {
  components.insert(std::make_pair(nextComponentId, std::make_shared<ColorPicker>(label, color)));
  ++nextComponentId;

  return static_pointer_cast<ColorPicker>(components[nextComponentId - 1]);
}

std::shared_ptr<FrameData> Window::addFrameData() {
  components.insert(std::make_pair(nextComponentId, std::make_shared<FrameData>()));
  ++nextComponentId;

  return static_pointer_cast<FrameData>(components[nextComponentId - 1]);
}

std::shared_ptr<Log> Window::addLog() {
  components.insert(std::make_pair(nextComponentId, std::make_shared<Log>()));
  ++nextComponentId;

  return static_pointer_cast<Log>(components[nextComponentId - 1]);
}

void Window::render() {
  int gameWindowWidth, gameWindowHeight;
  JollyGame::getInstance()->getGameWindowSize(gameWindowWidth, gameWindowHeight);

  ImGui::SetNextWindowPos(ImVec2(gameWindowWidth - width, 0));
  ImGui::SetNextWindowSize(ImVec2(width, height));

  ImGui::Begin(name.c_str());
  for (const auto &component : components) {
    component.second->render();
  }
  ImGui::End();
}
