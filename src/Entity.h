#pragma once

#include <array>

class Entity {
 public:
  Entity();
  ~Entity() = default;

  virtual const std::array<double, 3> GetPosition() const;
  virtual void SetPosition(const double &x, const double &y, const double &z);

 private:
  std::array<double, 3> position;
};
