#pragma once

#include "gui/Window.h"
#include <unordered_map>

#include <cstdint>
#include <memory>
#include <string>

class GuiManager {
 public:
  ~GuiManager() = default;

  static GuiManager* getInstance();

  void renderGui();
  std::shared_ptr<gui::Window> createWindow(const std::string &name, const uint32_t width, const uint32_t height);
  std::shared_ptr<gui::Window> getWindow(const std::string &name);
  void deleteWindow(const std::string &name);

 private:
  GuiManager() = default;

  std::unordered_map<std::string, std::shared_ptr<gui::Window>> windows;
};
