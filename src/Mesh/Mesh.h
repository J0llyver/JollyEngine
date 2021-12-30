#pragma once

#include <cstdint>

struct Mesh {
  float *vertices;
  uint32_t *indices;
  uint32_t numberOfVertices;
  uint32_t numberOfIndices;
};
