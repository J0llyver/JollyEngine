#include "Prop.h"

#include "CameraManager.h"
#include "JollyGame.h"
#include "Mesh/MeshFactory.h"
#include "Renderer.h"
#include "Rendering/ShaderFactory.h"
#include "glm/gtc/matrix_transform.hpp"

#include <fstream>
#include <stdexcept>

Prop::Prop(const std::string &meshId, const glm::vec3 &position) {
  this->meshId = meshId;
  modelMatrix = glm::translate(glm::mat4(1.0), position);
}

Prop::Prop(const MeshPrimitiveType &type, const glm::vec3 &position) {
  meshId = MeshFactory::getInstance()->loadPrimitive(type);
  modelMatrix = glm::translate(glm::mat4(1.0), position);
}

void Prop::scale(const double ratio) { scale(ratio, ratio, ratio); }

void Prop::scale(const double xRatio, const double yRatio, const double zRatio) {
  modelMatrix = glm::scale(modelMatrix, glm::vec3(xRatio, yRatio, zRatio));
}

void Prop::translate(const glm::vec3 &newPosition) { modelMatrix = glm::translate(modelMatrix, newPosition); }

void Prop::rotate(const float angle, const glm::vec3 &rotationAxis) {
  modelMatrix = glm::rotate(modelMatrix, angle, rotationAxis);
}

void Prop::pitch(const float angle) { rotate(angle, glm::vec3(1.0f, 0.0f, 0.0f)); }

void Prop::yaw(const float angle) { rotate(angle, glm::vec3(0.0f, 1.0f, 0.0f)); }

void Prop::roll(const float angle) { rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f)); }

int Prop::setTexture(const std::string &textureLocation) {
  std::ifstream textureFile(textureLocation.c_str());
  if (!textureFile.good()) {
    std::runtime_error("File does not exist: " + textureLocation);
    return -1;
  }

  this->textureLocation = textureLocation;

  return 0;
}

const glm::mat4 &Prop::getModelMatrix() const { return modelMatrix; }

int Prop::render() const {
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
