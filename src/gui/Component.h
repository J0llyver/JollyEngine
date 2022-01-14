#pragma once

namespace gui {

enum class ComponentType { ColorPicker, FloatSlider, FrameData, Log };

class Component {
 public:
  Component() = default;
  virtual ~Component() = default;
  virtual void render() = 0;
  virtual ComponentType getType() = 0;
};

}  // namespace gui
