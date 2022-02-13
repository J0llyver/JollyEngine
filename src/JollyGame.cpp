#include "JollyGame.h"

#include <iostream>
#include <stdexcept>

namespace {
void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
}  // namespace

JollyGame::JollyGame() {
  /* Initialize the library */
  if (!glfwInit()) {
    std::runtime_error("Failed to initialize glfw!");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  /* Create a windowed mode window and its OpenGL context */
  gameWindow = glfwCreateWindow(960, 540, "Canvas", NULL, NULL);

  if (!gameWindow) {
    glfwTerminate();
    std::runtime_error("Failed to initialize glfw!");
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(gameWindow);

  if (glewInit() != GLEW_OK) {
    std::runtime_error("Failed to initialize glew!");
  }

  glfwSetFramebufferSizeCallback(gameWindow, framebufferSizeCallback);

  const char* glsl_version = "#version 130";
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  // Setup Platform/Renderer bindings
  ImGui_ImplGlfw_InitForOpenGL(gameWindow, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  ImGui::StyleColorsDark();
}

JollyGame* JollyGame::getInstance() {
  static JollyGame game;
  return &game;
}

JollyGame::~JollyGame() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwTerminate();
}

void JollyGame::getGameWindowSize(int &width, int &height) { glfwGetWindowSize(gameWindow, &width, &height); }

bool JollyGame::windowShouldClose() { return glfwWindowShouldClose(gameWindow); }

void JollyGame::swapBuffers() { glfwSwapBuffers(gameWindow); }

void JollyGame::pollEvents() { glfwPollEvents(); }
