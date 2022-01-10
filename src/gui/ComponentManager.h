#pragma once

#include <cstdint>
#include <map>

#include "Component.h"

namespace gui {
class ComponentManager {
 public:
  ~Component()

      static std::shared_ptr<ComponentManager> getInstance();

 private:
  ComponentManager();

  // TODO: Handle uint32_t overflow
  uint32_t lastComponentId;

  std::map<uint32_t, Component *> components;
};
}  // namespace gui
