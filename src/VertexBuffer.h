#pragma once

#include <cstdint>

class VertexBuffer {
 private:
  unsigned int rendererID;

 public:
  VertexBuffer(const void *vertexBuffer, const uint32_t size);

  ~VertexBuffer();

  void Bind() const;
  void Unbind() const;
};
