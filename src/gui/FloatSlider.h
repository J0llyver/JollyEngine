#pragma once

#include <string>

#include "Component.h"

namespace gui {
class FloatSlider : public Component {
 public:
  FloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue, float* variable);
  ~FloatSlider() = default;

  virtual void render();
  virtual ComponentType getType();

 private:
  std::string label;
  float minimumValue;
  float maximumValue;
  float* variable;
};
}  // namespace gui
