#pragma once

#include "glm/glm.hpp"
#include "src/Entity.h"

class Camera : public Entity {
 public:
  Camera();
  ~Camera() = default;

  const glm::vec3 &getPosition() const;
  const glm::vec3 &getTarget() const;

  void setPosition(const float x, const float y, const float z);
  void setTarget(const glm::vec3 &target);

  const glm::mat4 &getProjectionMatrix() const;
  const glm::mat4 &getViewMatrix() const;

  void setProjectionMatrix(const float fieldOfView, const float aspectRatio, const float nearClippingPlane,
                           const float farClippingPlane);

 private:
  glm::vec3 position;
  glm::vec3 target;

  glm::vec3 viewDirection;
  glm::vec3 up;
  glm::vec3 right;

  glm::mat4 projectionMatrix;
  glm::mat4 viewMatrix;

  void updateProperties();
};
