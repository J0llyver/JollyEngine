#pragma once

#include "glm/glm.hpp"

class Rotateable {
 public:
  virtual void rotate(const float angle, const glm::vec3 &rotationAxis) = 0;
  virtual void pitch(const float angle) = 0;
  virtual void yaw(const float angle) = 0;
  virtual void roll(const float angle) = 0;
};
