#pragma once

#include "glm/glm.hpp"

class Movable {
 public:
  virtual void translate(const glm::vec3 &newPosition) = 0;
};
