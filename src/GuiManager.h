#pragma once

#include "gui/Window.h"

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

class GuiManager {
  public:
    ~GuiManager() = default;

    static GuiManager* getInstance();
    
    void renderGui();
    std::shared_ptr<gui::Window> createWindow(const std::string &name, const uint32_t width, const uint32_t height);
  
  private:
    GuiManager() = default;

    std::vector<std::shared_ptr<gui::Window>> windows;
};
