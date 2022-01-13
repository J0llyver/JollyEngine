#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "src/Mesh/Mesh.h"
#include "Shader/Shader.h"

class OpenGlRenderer {
 public:
  OpenGlRenderer() = default;
  ~OpenGlRenderer() = default;

  void clear() const;
  void draw(const Mesh &mesh, std::shared_ptr<Shader> &shader) const;
};
