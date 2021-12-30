#pragma once

#include <cstdint>
#include <vector>

class IndexBuffer {
 public:
  IndexBuffer(const std::vector<uint32_t> *indexBuffer, uint32_t size);
  IndexBuffer(const uint32_t *indexBuffer, uint32_t size);
  ~IndexBuffer();

  void Bind() const;
  void Unbind() const;

  inline uint32_t size() const { return numberOfIndices; }

 private:
  uint32_t rendererID;
  uint32_t numberOfIndices;
};
