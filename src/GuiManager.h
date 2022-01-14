#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#include "gui/Window.h"

class GuiManager {
 public:
  ~GuiManager() = default;

  static GuiManager* getInstance();

  void renderGui();
  std::shared_ptr<gui::Window> createWindow(const std::string &name, const uint32_t width, const uint32_t height);

 private:
  GuiManager() = default;

  std::unordered_map<std::string, std::shared_ptr<gui::Window>> windows;
};
