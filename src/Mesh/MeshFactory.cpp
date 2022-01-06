#include "MeshFactory.h"

#include <functional>

const std::string MeshFactory::loadPrimitive(const MeshPrimitiveType &type) {
  std::vector<float> newVertices;
  std::vector<uint32_t> newIndices;

  std::string meshId;
  std::function<void()> initializeMesh;

  switch (type) {
    case MeshPrimitiveType::Square: {
      meshId = "square";
      initializeMesh = [&](){ 
        initializeSquare(newVertices, newIndices);
      };
      break;
    }
    case MeshPrimitiveType::Triangle:
    default: {
      meshId = "triangle";
      initializeMesh = [&]() { 
        initializeTriangle(newVertices, newIndices);
      };
    }
  }

  if (meshMap.find(meshId) == meshMap.end()) {
    initializeMesh();

    const int startOfNewVertices = vertexBuffer.size();
    const int startOfNewIndices = indexBuffer.size();

    vertexBuffer.insert(vertexBuffer.end(), newVertices.begin(), newVertices.end());
    indexBuffer.insert(indexBuffer.end(), newIndices.begin(), newIndices.end());

    Mesh mesh = {&vertexBuffer[startOfNewVertices], &indexBuffer[startOfNewIndices],
                 static_cast<uint32_t>(newVertices.size()), static_cast<uint32_t>(newIndices.size())};

    meshMap.insert(std::pair(meshId, mesh));
  }

  return meshId;
}

const Mesh& MeshFactory::getMesh(const std::string &meshId) {
  return meshMap[meshId];
}

void MeshFactory::initializeTriangle(std::vector<float> &vertices, std::vector<uint32_t> &indices) const {
  vertices = {-0.5, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0};

  indices = {0, 1, 2};
}

void MeshFactory::initializeSquare(std::vector<float> &vertices, std::vector<uint32_t> &indices) const {
  vertices = {//-0.5, -0.5, 0.0,
              // 0.5, -0.5, 0.0,
              // 0.5, 0.5, 0.0,
              //-0.5, 0.5, 0.0
              0.0f, 0.0f, 0.0f, 0.0f, 100.0f, 0.0f, 1.0f, 0.0f, 100.0f, 100.0f, 1.0f, 1.0f, 0.0f, 100.0f, 0.0f, 1.0f};
  indices = {0, 1, 2, 2, 3, 0};
}
