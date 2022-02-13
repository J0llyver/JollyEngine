#pragma once

#include "Component.h"

#include <list>
#include <memory>
#include <string>

namespace gui {

class Window {
 public:
  Window() = default;
  Window(const std::string &name, const uint32_t width, const uint32_t height);
  ~Window() = default;

  void addComponent(const uint32_t componentId);

  uint32_t createFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue,
                             float* variable);
  uint32_t createColorPicker(const std::string &label, float* color);
  uint32_t createFrameData();
  uint32_t createLog();

  void render();

 private:
  std::string name;

  uint32_t width;
  uint32_t height;

  uint32_t nextComponentId;

  std::list<uint32_t> idsOfAttachedComponents;
};

}  // namespace gui
