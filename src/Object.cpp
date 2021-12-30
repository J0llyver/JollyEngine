#include "Object.h"

#include <fstream>
#include <iostream>

#include "Entity.h"
#include "glm/glm.hpp"
#include "src/ShaderFactory.h"

Object::Object(const Mesh &mesh) {
  this->mesh = &mesh;
  this->modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f));
}

int Object::Render(const Renderer &renderer) const {
  auto shader = ShaderFactory::GetInstance()->GetShader(ShaderType::Basic);

  // ToDo: Implement Camera and get projectionMatrix and view Matrix

  shader->Bind();

  glm::mat4 projectionMatrix = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
  glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
  glm::mat4 modelViewProjectionMatrix = projectionMatrix * viewMatrix * this->modelMatrix;

  shader->SetUniformMat4f("u_MVP", modelViewProjectionMatrix);
  shader->SetUniform1i("u_Texture", 0);
  shader->Unbind();

  return 0;
}

int Object::SetTexture(const std::string &textureLocation) {
  std::ifstream textureFile(textureLocation.c_str());
  if (!textureFile.good()) {
    std::cout << "File does not exist: " << textureLocation << std::endl;
    return -1;
  }

  this->textureLocation = textureLocation;

  return 0;
}

void Object::Scale(double ratio) { Scale(ratio, ratio, ratio); }

void Object::Scale(double xRatio, double yRatio, double zRatio) {
  modelMatrix = glm::scale(modelMatrix, glm::vec3(xRatio, yRatio, zRatio));
}
