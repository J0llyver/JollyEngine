#pragma once

#include <cstdint>
#include <string>

#include "glm/glm.hpp"

class Shader {
 public:
  Shader() = default;
  ~Shader() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  virtual void SetUniform1i(const std::string &name, int value) = 0;
  virtual void SetUniform4f(const std::string &name, float* values) = 0;
  virtual void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix) = 0;
};
