#include "Object.h"

#include <fstream>
#include <stdexcept>

#include "CameraManager.h"
#include "Entity.h"
#include "JollyGame.h"
#include "Mesh/MeshFactory.h"
#include "Renderer.h"
#include "Rendering/ShaderFactory.h"
#include "src/vendor/glm/gtc/matrix_transform.hpp"

Object::Object(const std::string &meshId, const glm::vec3 &position) {
  this->meshId = meshId;
  modelMatrix = glm::translate(glm::mat4(1.0), position);
}

Object::Object(const MeshPrimitiveType &type, const glm::vec3 &position) {
  meshId = MeshFactory::getInstance()->loadPrimitive(type);
  modelMatrix = glm::translate(glm::mat4(1.0), position);
}

void Object::scale(const double ratio) { scale(ratio, ratio, ratio); }

void Object::scale(const double xRatio, const double yRatio, const double zRatio) {
  modelMatrix = glm::scale(modelMatrix, glm::vec3(xRatio, yRatio, zRatio));
}

void Object::translate(const glm::vec3 &newPosition) { modelMatrix = glm::translate(modelMatrix, newPosition); }

void Object::rotate(const float angle, const glm::vec3 &rotationAxis) {
  modelMatrix = glm::rotate(modelMatrix, angle, rotationAxis);
}

void Object::pitch(const float angle) { rotate(angle, glm::vec3(1.0f, 0.0f, 0.0f)); }

void Object::yaw(const float angle) { rotate(angle, glm::vec3(0.0f, 1.0f, 0.0f)); }

void Object::roll(const float angle) { rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f)); }

int Object::setTexture(const std::string &textureLocation) {
  std::ifstream textureFile(textureLocation.c_str());
  if (!textureFile.good()) {
    std::runtime_error("File does not exist: " + textureLocation);
    return -1;
  }

  this->textureLocation = textureLocation;

  return 0;
}

const glm::mat4 &Object::getModelMatrix() const { return modelMatrix; }

int Object::render() const {
  auto shader = ShaderFactory::GetInstance()->GetShader(ShaderType::Basic);

  const auto camera = CameraManager::getInstance()->getCamera("main");

  glm::mat4 modelViewProjectionMatrix = camera->getProjectionMatrix() * camera->getViewMatrix() * modelMatrix;

  shader->Bind();
  shader->SetUniformMat4f("u_MVP", modelViewProjectionMatrix);
  shader->SetUniform1i("u_Texture", 0);
  shader->Unbind();

  Renderer::getInstance()->draw(meshId, shader);

  return 0;
}
