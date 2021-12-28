#pragma once

#include <memory>
#include <unordered_map>

#include "Shader/Shader.h"

enum ShaderType { BasicShader = 0 };

// Note: This Singleton is not thread save.
class ShaderFactory {
 private:
  ShaderFactory() = default;
  ~ShaderFactory() = default;

  std::unordered_map<ShaderType, std::shared_ptr<Shader>> shaders;

 public:
  ShaderFactory(ShaderFactory *other) = delete;
  void operator=(const ShaderFactory &) = delete;

  static std::shared_ptr<ShaderFactory> GetInstance();

  std::shared_ptr<Shader> GetShader(const ShaderType &type);
};
