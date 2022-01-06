#pragma once

#include <memory>
#include <vector>

#include "src/Renderer/OpenGlRenderer.h"
#include "src/Shader/Shader.h"

class Renderer {
 public:
  ~Renderer() = default;

  static Renderer *getInstance() {
    static Renderer rendererInstance;
    return &rendererInstance;
  }

  void clear();
  void draw(const std::string &meshId, std::shared_ptr<Shader> &shader);

 private:
  Renderer() = default;

  OpenGlRenderer renderer;
};
