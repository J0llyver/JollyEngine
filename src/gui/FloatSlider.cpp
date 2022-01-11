#include "FloatSlider.h"

#include "imgui/imgui.h"

gui::FloatSlider::FloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue,
                              float* variable) {
  this->label = label;
  this->minimumValue = minimumValue;
  this->maximumValue = maximumValue;
  this->variable = variable;
}

void gui::FloatSlider::render() {
  if (variable != nullptr) {
    ImGui::SliderFloat(label.c_str(), variable, minimumValue, maximumValue);
  } else {
    ImGui::Text("Invalid variable for slider '%s'!", label.c_str());
  }
}

gui::ComponentType gui::FloatSlider::getType() { return ComponentType::FloatSlider; }
