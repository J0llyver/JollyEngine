#pragma once

#include <string>

#include "src/Entity.h"
#include "src/Mesh/Mesh.h"
#include "src/Renderer/Renderer.h"
#include "src/vendor/glm/gtc/matrix_transform.hpp"

// ToDo: Add pipline for rendering behaviour
// ToDo: Add ppipline fo game behaviour
class Object : Entity {
 public:
  Object(const Mesh &mesh);
  ~Object() = default;

  inline void Scale(const double x);
  void Scale(double xRatio, double yRatio, double zRatio);

  int SetTexture(const std::string &textureLocation);

  int Render(const Renderer &renderer) const;

 private:
  const Mesh *mesh;
  glm::mat4 modelMatrix;

  std::string textureLocation;
};
