#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>

class JollyGame {
 public:
  ~JollyGame();

  static JollyGame* getInstance();

  void getGameWindowSize(int &width, int &height);

  bool windowShouldClose();
  void swapBuffers();
  void pollEvents();

 private:
  JollyGame();

  GLFWwindow* gameWindow;
};
