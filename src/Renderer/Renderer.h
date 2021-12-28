#pragma once

#include <vector>

#include "src/IndexBuffer.h"
#include "src/Shader/Shader.h"
#include "src/VertexArray.h"

class Renderer {
 public:
  virtual void Clear() const = 0;
  virtual void Draw(const float *vertices, const uint32_t *indices, const uint32_t numberOfVertices,
                    std::shared_ptr<Shader> &shader) const = 0;
};
