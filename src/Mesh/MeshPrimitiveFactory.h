#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "MeshPrimitive.h"

struct Mesh {
  float *vertices;
  uint32_t *indices;
  uint32_t numberOfVertices;
  uint32_t numberOfIndices;
};

class MeshPrimitiveFactory {
 public:
  MeshPrimitiveFactory() = default;
  ~MeshPrimitiveFactory() = default;

  MeshPrimitiveFactory(MeshPrimitiveFactory const &) = delete;
  void operator=(MeshPrimitiveFactory const &) = delete;

  Mesh LoadPrimitive(const MeshPrimitive::Type &type);

 private:
  const Mesh &CreatePrimitive(const MeshPrimitive::Type &type);
  void InitializeTriangle(std::vector<float> &vertices, std::vector<uint32_t> &indices) const;
  void InitializeSquare(std::vector<float> &vertices, std::vector<uint32_t> &indices) const;

  std::unordered_map<uint32_t, Mesh> meshMap;
  std::vector<float> vertexBuffer;
  std::vector<uint32_t> indexBuffer;
};
