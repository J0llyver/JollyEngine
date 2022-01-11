#include "FrameData.h"

#include "imgui/imgui.h"

void gui::FrameData::render() {
  ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
              ImGui::GetIO().Framerate);
}

gui::ComponentType gui::FrameData::getType() { return ComponentType::FrameData; }
