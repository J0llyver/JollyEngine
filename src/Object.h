#pragma once

#include <string>

#include "src/Entity.h"
#include "src/Mesh/Mesh.h"

// ToDo: Add pipline fo game behaviour
class Object : public Entity {
 public:
  Object(const std::string &meshId, const glm::vec3 &position);
  Object(const MeshPrimitiveType &type, const glm::vec3 &position);
  ~Object() = default;

  void scale(const double x);
  void scale(double xRatio, double yRatio, double zRatio);
  void translate(const glm::vec3 &newPosition);

  void rotate(const float angle, const glm::vec3 &rotationAxis);
  void pitch(const float angle);
  void yaw(const float angle);
  void roll(const float angle);

  int setTexture(const std::string &textureLocation);

  const glm::mat4 &getModelMatrix() const;

  int render() const;

 private:
  std::string meshId;
  glm::mat4 modelMatrix;

  std::string textureLocation;
};
