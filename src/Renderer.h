#pragma once

#include "Rendering/OpenGlRenderer.h"
#include "Rendering/Shader/Shader.h"

#include <memory>
#include <vector>

class Renderer {
 public:
  ~Renderer() = default;

  static Renderer* getInstance();

  void clear();
  void draw(const std::string &meshId, std::shared_ptr<Shader> &shader);

 private:
  Renderer() = default;

  OpenGlRenderer renderer;
};
