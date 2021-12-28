#include "Entity.h"

Entity::Entity() {
  position[0] = 0.0;
  position[1] = 0.0;
  position[2] = 0.0;
}

const std::array<double, 3> Entity::GetPosition() const { return position; }

void Entity::SetPosition(const double &x, const double &y, const double &z) {
  position[0] = x;
  position[1] = y;
  position[2] = z;
}
