#pragma once

#include "Scenery/Camera.h"
#include <unordered_map>

#include <memory>
#include <string>

class CameraManager {
 public:
  ~CameraManager() = default;

  static CameraManager* getInstance();

  std::shared_ptr<Camera> createCamera(const std::string &name);
  std::shared_ptr<Camera> getCamera(const std::string &name);

 private:
  CameraManager() = default;

  std::unordered_map<std::string, std::shared_ptr<Camera>> cameras;
};
