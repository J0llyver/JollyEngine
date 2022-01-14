#include "Log.h"

void gui::Log::render() { ImGui::Text(logBuffer.c_str()); }

gui::ComponentType gui::Log::getType() { return ComponentType::Log; }

void gui::Log::log(const std::string &message) { logBuffer.append(message.c_str()); }

void gui::Log::clear() { logBuffer.clear(); }
