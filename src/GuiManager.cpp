#include "GuiManager.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

GuiManager* GuiManager::getInstance() {
  static GuiManager guiManager;
  return &guiManager;
}

void GuiManager::renderGui() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  for (const auto &window : windows) {
    window.second->render();
  }

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

std::shared_ptr<gui::Window> GuiManager::createWindow(const std::string &name, const uint32_t width,
                                                      const uint32_t height) {
  if (windows.find(name) == windows.end()) {
    windows.insert(std::make_pair(name, std::make_shared<gui::Window>(name, width, height)));
    return windows[name];
  } else {
    return windows[name];
  }
}

std::shared_ptr<gui::Window> GuiManager::getWindow(const std::string &name) {
  if (windows.find(name) != windows.end()) {
    return windows[name];
  }

  return nullptr;
}

void GuiManager::deleteWindow(const std::string &name) {
  if (windows.find(name) != windows.end()) {
    windows.erase(name);
  }
}
