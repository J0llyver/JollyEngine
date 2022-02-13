#pragma once

#include "Component.h"
#include "imgui/imgui.h"

#include <string>

namespace gui {
class Log : public Component {
 public:
  Log() = default;
  ~Log() = default;

  void render();
  ComponentType getType();

  void log(std::string message);
  void clear();

 private:
  ImGuiTextBuffer logBuffer;
};
}  // namespace gui
