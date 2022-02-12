#include "Camera.h"

#include "JollyGame.h"
#include "vendor/glm/gtc/matrix_transform.hpp"

Camera::Camera() {
  position = glm::vec3(0.0f, 0.0f, 50.0f);
  target = glm::vec3(0.0f, 0.0f, 0.0f);

  updateProperties();

  int gameWindowWidth, gameWindowHeight;
  JollyGame::getInstance()->getGameWindowSize(gameWindowWidth, gameWindowHeight);
  setProjectionMatrix(45, (float)gameWindowWidth / (float)gameWindowHeight, 1.0f, 200.0f);
}

const glm::vec3 &Camera::getPosition() const { return position; }

void Camera::setPosition(const float x, const float y, const float z) {
  position[0] = x;
  position[1] = y;
  position[2] = z;

  updateProperties();
}

const glm::vec3 &Camera::getTarget() const { return target; }

void Camera::setTarget(const glm::vec3 &target) {
  this->target = target;

  updateProperties();
}

const glm::mat4 &Camera::getProjectionMatrix() const { return projectionMatrix; }

void Camera::setProjectionMatrix(const float fieldOfView, const float aspectRatio, const float nearClippingPlane,
                                 const float farClippingPlane) {
  projectionMatrix = glm::perspective(glm::radians(fieldOfView), aspectRatio, nearClippingPlane, farClippingPlane);
}

const glm::mat4 &Camera::getViewMatrix() const { return viewMatrix; }

void Camera::updateProperties() {
  viewDirection = glm::normalize(position - target);

  const glm::vec3 globalUp = glm::vec3(0.0f, 1.0f, 0.0f);
  right = glm::normalize(glm::cross(globalUp, viewDirection));
  up = glm::cross(viewDirection, right);

  viewMatrix = glm::lookAt(position, target, up);
}
