#pragma once

#include "Mesh/Mesh.h"
#include "Shader/Shader.h"
#include <unordered_map>

#include <memory>
#include <vector>

class OpenGlRenderer {
 public:
  OpenGlRenderer();
  ~OpenGlRenderer() = default;

  void clear() const;
  void draw(const Mesh &mesh, std::shared_ptr<Shader> &shader) const;
};
