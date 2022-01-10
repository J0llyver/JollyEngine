#include "ComponentManger.h"

gui::ComponentManager::ComponentManager() {
  components.insert(std::make_pair<0, static_cast<Component*>(&frameData));
  ++newComponentId;
}

std::shared_ptr<ComponentManager> gui::ComponentManager::getInstance() {
  static ComponentManger instance;

  return instance;
}

uint32_t gui::ComponentManager::createFloatSlider(const std::string &label, const float &minimumValue, const float &maximumValue, float *variable) {
  gui::FloatSlider newFloatSlider(label, minimumValue, maximumValue);

  floatSliders.push(std::make_pair(nextComponentId, newFloatSlider));
  components.insert(std::make_pair(nextComponentId, &(floatSliders.back());

  ++nextComponentId;

  return nextComponentId - 1;
}

uint32_t gui::ComponentMangager::createColorPicker(const std::string &label, float *colorVariable) {
  gui::ColorPicker newColorPicker(label, colorVariable);

  colorPickers.push(std::make_pair(nextComponentId, newColorPicker));
  components.insert(std::make_pair(nextComponentId, &(colorPickers.back());
  
  ++nextComponentId;

  return nextComponentId - 1;
}

uint32_t gui::ComponentManager::getFrameData() {
  return 0;
}

gui::Component* gui::ComponentManager::getComponent(const uint32_t id) const {
  return components[id];
}

void gui::ComponentManager::clear() {
  components.clear();
  floatSliders.clear();
  colorPickers.clear();

  components.insert(std::make_pair<0, static_cast<Component*>(&frameData));

  nextComponentId = 1;
}
