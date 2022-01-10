#pragma once

#include <cstdint>
#include <map>
#include <unordered_map>

#include "ColorPicker.h"
#include "FloatSlider.h"
#include "FrameData.h"

namespace gui {
class ComponentManager {
 public:
  ~Component() = default;

  static std::shared_ptr<ComponentManager> getInstance();

  uint32_t createFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue,
                             float *variable);
  uint32_t createColorPicker(const std::string &label, float *colorVariable);

  Component *getComponent(const uint32_t id);
  Component *getFrameData();

  void clear();

 private:
  ComponentManager() = default;

  // TODO: Handle uint32_t overflow
  uint32_t nextComponentId;

  std::map<uint32_t, Component *> components;

  FrameData frameData;

  std::unordered_map<uint32_t, FloatSlider> floatSliders;
  std::unordered_map<uint32_t, ColorPicker> colorPickers;
};
}  // namespace gui
