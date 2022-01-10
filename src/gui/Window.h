#pragma once

#include <unordered_map>

#include "Component.h"
#include "glm/glm.hpp"

namespace gui {
class Window {
 public:
  Window() = default;
  Window(const uint32_t width, const uint32_t height);
  ~Window() = default;

  void addFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue, float *variable);
  void addColorEditor(const std::string &label, float *color);
  void addFrameData(std::string text);

  void render();

 private:
  std::string name;

  uint32_t width;
  uint32_t height;

  std::unordered_map<uint32_t, Component *> components;
};

}  // namespace gui
