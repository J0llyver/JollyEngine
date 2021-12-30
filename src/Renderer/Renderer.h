#pragma once

#include <memory>
#include <vector>

#include "src/IndexBuffer.h"
#include "src/Mesh/Mesh.h"
#include "src/Shader/Shader.h"
#include "src/VertexArray.h"

class Renderer {
 public:
  virtual void Clear() const = 0;
  virtual void Draw(const Mesh &mesh, std::shared_ptr<Shader> &shader) const = 0;
};
