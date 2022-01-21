#include "CameraManager.h"

CameraManager* CameraManager::getInstance() {
  static CameraManager instance;
  return &instance;
}

std::shared_ptr<Camera> CameraManager::createCamera(const std::string &name) {
  cameras.insert(std::make_pair(name, std::make_shared<Camera>()));
  return cameras[name];
}

std::shared_ptr<Camera> CameraManager::getCamera(const std::string &name) { return cameras[name]; }
