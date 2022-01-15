#pragma once

#include <memory>
#include <unordered_map>

#include "ColorPicker.h"
#include "Component.h"
#include "FloatSlider.h"
#include "FrameData.h"
#include "Log.h"

namespace gui {
class ComponentManager {
 public:
  ~ComponentManager() = default;

  static ComponentManager* getInstance();

  uint32_t createColorPicker(const std::string &label, float* color);
  uint32_t createFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue,
                             float* variable);
  uint32_t createFrameData();
  uint32_t createLog();

  std::shared_ptr<ColorPicker> getColorPicker(const uint32_t id);
  std::shared_ptr<FloatSlider> getFloatSlider(const uint32_t id);
  std::shared_ptr<FrameData> getFrameData(const uint32_t id);
  std::shared_ptr<Log> getLog(const uint32_t id);

  /**
   * This function needs to be called between ImGui::Begin() and ImGui::End() and therefore should only be used in
   * gui::Window::render().
   */
  void renderComponent(const uint32_t componentId);

 private:
  ComponentManager() = default;

  static ComponentManager* instance;

  uint32_t nextComponentId = 0;

  std::unordered_map<uint32_t, std::shared_ptr<Component>> components;

  std::unordered_map<uint32_t, std::shared_ptr<ColorPicker>> colorPickers;
  std::unordered_map<uint32_t, std::shared_ptr<FloatSlider>> floatSliders;
  std::unordered_map<uint32_t, std::shared_ptr<FrameData>> frameData;
  std::unordered_map<uint32_t, std::shared_ptr<Log>> logs;

  uint32_t addComponent(const std::shared_ptr<Component> &component);
};
}  // namespace gui
