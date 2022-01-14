#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#include "ColorPicker.h"
#include "Component.h"
#include "FloatSlider.h"
#include "FrameData.h"
#include "Log.h"

namespace gui {

class Window {
 public:
  Window() = default;
  Window(const std::string &name, const uint32_t width, const uint32_t height);
  ~Window() = default;

  std::shared_ptr<FloatSlider> addFloatSlider(const std::string &label, const float &minimumValue,
                                              const float &maximumValue, float* variable);
  std::shared_ptr<ColorPicker> addColorPicker(const std::string &label, float* color);
  std::shared_ptr<FrameData> addFrameData();
  std::shared_ptr<Log> addLog();

  void render();

 private:
  std::string name;

  uint32_t width;
  uint32_t height;

  uint32_t nextComponentId;

  std::unordered_map<uint32_t, std::shared_ptr<Component>> components;
};

}  // namespace gui
