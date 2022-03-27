#pragma once

#include "Mesh/Mesh.h"
#include "Movable.h"
#include "Rotateable.h"

#include <string>

class Prop : public Rotateable, public Movable {
 public:
  Prop(const std::string &meshId, const glm::vec3 &position);
  Prop(const MeshPrimitiveType &type, const glm::vec3 &position);
  ~Prop() = default;

  void scale(const double x);
  void scale(double xRatio, double yRatio, double zRatio);

  void translate(const glm::vec3 &newPosition) override;

  void rotate(const float angle, const glm::vec3 &rotationAxis) override;
  void pitch(const float angle) override;
  void yaw(const float angle) override;
  void roll(const float angle) override;

  int setTexture(const std::string &textureLocation);

  const glm::mat4 &getModelMatrix() const;

  int render() const;

 private:
  std::string meshId;
  glm::mat4 modelMatrix;

  std::string textureLocation;
};
