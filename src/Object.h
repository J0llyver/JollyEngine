#pragma once

#include <string>

#include "src/Entity.h"
#include "src/Mesh/Mesh.h"
#include "src/vendor/glm/gtc/matrix_transform.hpp"

// ToDo: Add pipline for rendering behaviour
// ToDo: Add pipline fo game behaviour
class Object : Entity {
 public:
  Object(const std::string &meshId, const glm::vec3 &position);
  Object(const MeshPrimitiveType &type, const glm::vec3 &position);
  ~Object() = default;

  inline void scale(const double x);
  void scale(double xRatio, double yRatio, double zRatio);
  void translate(const glm::vec3 &newPosition);

  int setTexture(const std::string &textureLocation);

  const glm::mat4 &getModelMatrix() const;

  int render() const;

 private:
  std::string meshId;
  glm::mat4 modelMatrix;

  std::string textureLocation;
};
