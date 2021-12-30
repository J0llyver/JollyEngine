#pragma once

#include <unordered_map>
#include <vector>

#include "src/Mesh/Mesh.h"
#include "src/Mesh/MeshPrimitive.h"

class MeshPrimitiveFactory {
 public:
  MeshPrimitiveFactory() = default;
  ~MeshPrimitiveFactory() = default;

  MeshPrimitiveFactory(MeshPrimitiveFactory const &) = delete;
  void operator=(MeshPrimitiveFactory const &) = delete;

  Mesh LoadPrimitive(const MeshPrimitive::Type &type);

 private:
  void CreatePrimitive(const MeshPrimitive::Type &type);
  void InitializeTriangle(std::vector<float> &vertices, std::vector<uint32_t> &indices) const;
  void InitializeSquare(std::vector<float> &vertices, std::vector<uint32_t> &indices) const;

  std::unordered_map<uint32_t, Mesh> meshMap;
  std::vector<float> vertexBuffer;
  std::vector<uint32_t> indexBuffer;
};
