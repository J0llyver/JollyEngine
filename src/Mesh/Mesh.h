#pragma once

#include <cstdint>

enum MeshPrimitiveType { Square = 0, Triangle = 1 };

struct Mesh {
  float *vertices;
  uint32_t *indices;
  uint32_t numberOfVertices;
  uint32_t numberOfIndices;
};
