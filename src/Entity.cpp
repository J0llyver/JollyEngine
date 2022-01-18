#include "Entity.h"

Entity::Entity() {
  position[0] = 0.0;
  position[1] = 0.0;
  position[2] = 0.0;
}

const glm::vec3 &Entity::getPosition() const { return position; }

void Entity::setPosition(const float &x, const float &y, const float &z) {
  position[0] = x;
  position[1] = y;
  position[2] = z;
}

const glm::vec3 &Entity::getRotation() const { return rotation; }

void Entity::setRotation(const float &x, const float &y, const float &z) {
  rotation[0] = x;
  rotation[1] = y;
  rotation[2] = z;
}
