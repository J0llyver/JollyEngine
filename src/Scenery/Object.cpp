#include "Object.h"

Object::Object() {
  position[0] = 0.0;
  position[1] = 0.0;
  position[2] = 0.0;
}

const glm::vec3 &Object::getPosition() const { return position; }

void Object::setPosition(const float &x, const float &y, const float &z) {
  position[0] = x;
  position[1] = y;
  position[2] = z;
}

const glm::vec3 &Object::getRotation() const { return rotation; }

void Object::setRotation(const float &x, const float &y, const float &z) {
  rotation[0] = x;
  rotation[1] = y;
  rotation[2] = z;
}
