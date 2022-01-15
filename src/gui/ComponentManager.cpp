#include "ComponentManager.h"

#include <iostream>
#include <stdexcept>

using namespace gui;

ComponentManager* ComponentManager::getInstance() {
  static ComponentManager instance;
  return &instance;
}

std::shared_ptr<ColorPicker> ComponentManager::getColorPicker(const uint32_t id) {
  auto instance = getInstance();
  if (instance->colorPickers.find(id) != instance->colorPickers.end()) {
    // If id exists in colorPickers, it has to exist in components;
    return std::static_pointer_cast<ColorPicker>(instance->components[id]);
  }

  return nullptr;
}

std::shared_ptr<FloatSlider> ComponentManager::getFloatSlider(const uint32_t id) {
  if (floatSliders.find(id) != floatSliders.end()) {
    // If id exists in floatSliders, it has to exist in components;
    return std::static_pointer_cast<FloatSlider>(components[id]);
  }

  return nullptr;
}

std::shared_ptr<FrameData> ComponentManager::getFrameData(const uint32_t id) {
  if (frameData.find(id) != frameData.end()) {
    // If id exists in frameData, it has to exist in components;
    return std::static_pointer_cast<FrameData>(components[id]);
  }

  return nullptr;
}

std::shared_ptr<Log> ComponentManager::getLog(const uint32_t id) {
  if (logs.find(id) != logs.end()) {
    // If id exists in logs, it has to exist in components;
    return std::static_pointer_cast<Log>(components[id]);
  }

  return nullptr;
}

uint32_t ComponentManager::createColorPicker(const std::string &label, float* color) {
  colorPickers.insert(std::make_pair(nextComponentId, std::make_shared<ColorPicker>(label, color)));
  return addComponent(std::static_pointer_cast<Component>(colorPickers[nextComponentId]));
}

uint32_t ComponentManager::createFloatSlider(const std::string &label, const float &minimumValue,
                                             const float &maximumValue, float* variable) {
  floatSliders.insert(
      std::make_pair(nextComponentId, std::make_shared<FloatSlider>(label, minimumValue, maximumValue, variable)));
  return addComponent(std::static_pointer_cast<Component>(floatSliders[nextComponentId]));
}

uint32_t ComponentManager::createFrameData() {
  frameData.insert(std::make_pair(nextComponentId, std::make_shared<FrameData>()));
  return addComponent(std::static_pointer_cast<Component>(frameData[nextComponentId]));
}

uint32_t ComponentManager::createLog() {
  logs.insert(std::make_pair(nextComponentId, std::make_shared<Log>()));
  return addComponent(std::static_pointer_cast<Component>(logs[nextComponentId]));
}

void ComponentManager::renderComponent(const uint32_t componentId) {
  if (components.find(componentId) != components.end()) {
    components[componentId]->render();
  }
}

uint32_t ComponentManager::addComponent(const std::shared_ptr<Component> &component) {
  components.insert(std::make_pair(nextComponentId, component));

  ++nextComponentId;

  std::cout << "Next component id: " << nextComponentId << std::endl;

  return nextComponentId - 1;
}
