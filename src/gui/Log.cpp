#include "Log.h"

void gui::Log::render() { ImGui::Text(logBuffer.c_str()); }

gui::ComponentType gui::Log::getType() { return ComponentType::Log; }

void gui::Log::log(std::string message) {
  message += "\n";
  logBuffer.append(message.c_str());
}

void gui::Log::clear() { logBuffer.clear(); }
