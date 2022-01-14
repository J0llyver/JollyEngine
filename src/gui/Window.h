#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include "Component.h"

namespace gui {

class Window {
 public:
  Window() = default;
  Window(const std::string &name, const uint32_t width, const uint32_t height);
  ~Window() = default;

  uint32_t addFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue,
                          float* variable);
  uint32_t addColorPicker(const std::string &label, float* color);
  uint32_t addFrameData();
  uint32_t addLog();

  void render();

 private:
  std::string name;

  uint32_t width;
  uint32_t height;

  uint32_t nextComponentId;

  std::unordered_map<uint32_t, Component*> components;
};

}  // namespace gui
