#include "Window.h"

#include "ColorPicker.h"
#include "FloatSlider.h"
#include "FrameData.h"
#include "imgui/imgui.h"
#include "src/JollyGame.h"

gui::Window::Window(const std::string &name, const uint32_t width, const uint32_t height) {
  this->name = name;
  this->width = width;
  this->height = height;
}

void gui::Window::addFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue,
                                 float* variable) {
  components.insert(std::make_pair(
      nextComponentId, static_cast<Component*>(new FloatSlider(label, minimumValue, maximumValue, variable))));
  ++nextComponentId;
}

void gui::Window::addColorPicker(const std::string &label, float* color) {
  components.insert(std::make_pair(nextComponentId, static_cast<Component*>(new ColorPicker(label, color))));
  ++nextComponentId;
}

void gui::Window::addFrameData() {
  components.insert(std::make_pair(nextComponentId, static_cast<Component*>(new FrameData())));
  ++nextComponentId;
}

void gui::Window::render() {
  int gameWindowWidth, gameWindowHeight;
  JollyGame::getInstance()->getGameWindowSize(gameWindowWidth, gameWindowHeight);

  ImGui::SetNextWindowPos(ImVec2(gameWindowWidth - width, 0));
  ImGui::SetNextWindowSize(ImVec2(width, height));

  ImGui::Begin(name.c_str());
  for (const auto component : components) {
    component.second->render();
  }
  ImGui::End();
}
