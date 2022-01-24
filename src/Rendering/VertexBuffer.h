#pragma once

#include <cstdint>

class VertexBuffer {
 public:
  VertexBuffer(const void* vertexBuffer, const uint32_t size);
  ~VertexBuffer();

  inline uint32_t size() const { return numberOfVertices; }

  void Bind() const;
  void Unbind() const;

 private:
  uint32_t rendererID;
  uint32_t numberOfVertices;
};
