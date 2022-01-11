#include "ColorPicker.h"

#include "imgui/imgui.h"

gui::ColorPicker::ColorPicker(const std::string &label, float *colorVariable) {
  this->label = label;
  this->colorVariable = colorVariable;
}

void gui::ColorPicker::render() {
  if (colorVariable != nullptr) {
    ImGui::ColorEdit3(label.c_str(), colorVariable);
  } else {
    ImGui::Text("Invalid variable for color picker '%s'!", label.c_str());
  }
}

gui::ComponentType gui::ColorPicker::getType() { return ComponentType::ColorPicker; }
