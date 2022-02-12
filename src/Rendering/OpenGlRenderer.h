#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "Shader/Shader.h"
#include "Mesh/Mesh.h"

class OpenGlRenderer {
 public:
  OpenGlRenderer();
  ~OpenGlRenderer() = default;

  void clear() const;
  void draw(const Mesh &mesh, std::shared_ptr<Shader> &shader) const;
};
