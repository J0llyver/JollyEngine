#pragma once

#include <string>

#include "Component.h"
#include "imgui/imgui.h"

namespace gui {
class Log : public Component {
 public:
  Log() = default;
  ~Log() = default;

  void render();
  ComponentType getType();

  void log(const std::string &message);
  void clear();

 private:
  ImGuiTextBuffer logBuffer;
};
}  // namespace gui
