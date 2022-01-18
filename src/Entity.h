#pragma once

#include <array>

#include "glm/glm.hpp"

class Entity {
 public:
  Entity();
  ~Entity() = default;

  const glm::vec3 &getPosition() const;
  void setPosition(const float &x, const float &y, const float &z);

  const glm::vec3 &getRotation() const;
  void setRotation(const float &x, const float &y, const float &z);

 private:
  glm::vec3 position;
  glm::vec3 rotation;
};
