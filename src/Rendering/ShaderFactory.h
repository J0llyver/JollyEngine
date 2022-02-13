#pragma once

#include "Shader/Shader.h"
#include <unordered_map>

#include <memory>

enum ShaderType { Basic = 0 };

// Note: This Singleton is not thread save.
class ShaderFactory {
 public:
  ~ShaderFactory() = default;

  ShaderFactory(ShaderFactory* other) = delete;
  void operator=(const ShaderFactory &) = delete;

  static std::shared_ptr<ShaderFactory> GetInstance();

  std::shared_ptr<Shader> GetShader(const ShaderType &type);

 private:
  ShaderFactory() = default;

  std::unordered_map<uint32_t, std::shared_ptr<Shader>> shaders;
};
