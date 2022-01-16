#include "Object.h"

#include <fstream>
#include <stdexcept>

#include "Entity.h"
#include "JollyGame.h"
#include "Mesh/MeshFactory.h"
#include "Renderer.h"
#include "Rendering/ShaderFactory.h"
#include "glm/glm.hpp"

Object::Object(const std::string &meshId, const glm::vec3 &position) {
  this->meshId = meshId;
  modelMatrix = glm::translate(glm::mat4(1.0f), position);
}

Object::Object(const MeshPrimitiveType &type, const glm::vec3 &position) {
  this->meshId = MeshFactory::getInstance()->loadPrimitive(type);
  modelMatrix = glm::translate(glm::mat4(1.0f), position);
}

void Object::scale(double ratio) { scale(ratio, ratio, ratio); }

void Object::scale(double xRatio, double yRatio, double zRatio) {
  modelMatrix = glm::scale(modelMatrix, glm::vec3(xRatio, yRatio, zRatio));
}

void Object::translate(const glm::vec3 &newPosition) { modelMatrix = glm::translate(glm::mat4(1.0f), newPosition); }

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

  // ToDo: Implement Camera and get projectionMatrix and view Matrix

  int gameWindowWidth, gameWindowHeight;
  JollyGame::getInstance()->getGameWindowSize(gameWindowWidth, gameWindowHeight);
  glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)gameWindowWidth, 0.0f, (float)gameWindowHeight, -1.0f, 1.0f);
  glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
  glm::mat4 modelViewProjectionMatrix = projectionMatrix * viewMatrix * this->modelMatrix;

  shader->Bind();
  shader->SetUniformMat4f("u_MVP", modelViewProjectionMatrix);
  shader->SetUniform1i("u_Texture", 0);
  shader->Unbind();

  Renderer::getInstance()->draw(meshId, shader);

  return 0;
}
