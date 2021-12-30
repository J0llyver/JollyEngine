#include "MeshPrimitiveFactory.h"

Mesh MeshPrimitiveFactory::LoadPrimitive(const MeshPrimitive::Type &type) {
  const uint32_t typeId = static_cast<uint32_t>(type);
  if (meshMap.find(typeId) == meshMap.end()) {
    CreatePrimitive(type);
  }

  return meshMap[typeId];
}

void MeshPrimitiveFactory::CreatePrimitive(const MeshPrimitive::Type &type) {
  std::vector<float> newVertices;
  std::vector<uint32_t> newIndices;

  switch (type) {
    case MeshPrimitive::Square: {
      InitializeSquare(newVertices, newIndices);
      break;
    }
    case MeshPrimitive::Triangle:
    default: {
      InitializeTriangle(newVertices, newIndices);
    }
  }

  const int startOfNewVertices = vertexBuffer.size();
  const int startOfNewIndices = indexBuffer.size();

  vertexBuffer.insert(vertexBuffer.end(), newVertices.begin(), newVertices.end());
  indexBuffer.insert(indexBuffer.end(), newIndices.begin(), newIndices.end());

  Mesh mesh = {&vertexBuffer[startOfNewVertices], &indexBuffer[startOfNewIndices],
               static_cast<uint32_t>(newVertices.size()), static_cast<uint32_t>(newIndices.size())};

  meshMap.insert(std::pair(static_cast<uint32_t>(type), mesh));
}

void MeshPrimitiveFactory::InitializeTriangle(std::vector<float> &vertices, std::vector<uint32_t> &indices) const {
  vertices = {-0.5, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0};

  indices = {0, 1, 2};
}

void MeshPrimitiveFactory::InitializeSquare(std::vector<float> &vertices, std::vector<uint32_t> &indices) const {
  vertices = {//-0.5, -0.5, 0.0,
              // 0.5, -0.5, 0.0,
              // 0.5, 0.5, 0.0,
              //-0.5, 0.5, 0.0
              0.0f, 0.0f, 0.0f, 0.0f, 100.0f, 0.0f, 1.0f, 0.0f, 100.0f, 100.0f, 1.0f, 1.0f, 0.0f, 100.0f, 0.0f, 1.0f};
  indices = {0, 1, 2, 2, 3, 0};
}
