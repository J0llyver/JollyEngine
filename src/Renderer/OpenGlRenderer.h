#pragma once

#include <memory>
#include <vector>

#include "Renderer.h"
#include "src/Shader/Shader.h"

class OpenGlRenderer : Renderer {
 public:
  OpenGlRenderer() = default;
  ~OpenGlRenderer() = default;

  void Clear() const override;
  void Draw(const std::vector<float> &vertexArray, const std::vector<unsigned int> &indexBufer,
            const std::shared_ptr<Shader> &shader) const override;

  void BindVertexBuffer(const std::vector<float> &vertexBuffer, const VertexBufferLayout &layout);
  void UnbindVertexBuffer(/* TODO: poperly define method */);

 private:
  std::unordered_map<unsigned int, VertexBuffer> vertexBuffers;
};
