#pragma once

#include "Component.h"

#include <string>

namespace gui {
class ColorPicker : public Component {
 public:
  ColorPicker(const std::string &label, float* colorVariable);
  ~ColorPicker() = default;

  virtual void render();
  virtual ComponentType getType();

 private:
  std::string label;
  float* colorVariable;
};
}  // namespace gui
