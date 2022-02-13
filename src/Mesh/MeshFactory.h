#pragma once

#include "Mesh/Mesh.h"
#include <unordered_map>

#include <string>
#include <vector>

class MeshFactory {
 public:
  ~MeshFactory() = default;

  MeshFactory(MeshFactory const &) = delete;
  void operator=(MeshFactory const &) = delete;

  static MeshFactory* getInstance() {
    static MeshFactory meshFactoryInstance;
    return &meshFactoryInstance;
  }

  const std::string loadPrimitive(const MeshPrimitiveType &type);
  const Mesh &getMesh(const std::string &meshId);

 private:
  MeshFactory() = default;

  void createPrimitive(const MeshPrimitiveType &type);
  void initializeTriangle(std::vector<float> &vertices, std::vector<uint32_t> &indices) const;
  void initializeSquare(std::vector<float> &vertices, std::vector<uint32_t> &indices) const;

  std::unordered_map<std::string, Mesh> meshMap;
  std::vector<float> vertexBuffer;
  std::vector<uint32_t> indexBuffer;
};
