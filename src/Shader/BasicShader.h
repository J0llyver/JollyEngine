#pragma once

#include <string>
#include <unordered_map>

#include "Shader.h"

struct ShaderProgramSource {
  std::string VertexSource;
  std::string FragmentSource;
};

class BasicShader : public Shader {
 public:
  BasicShader(const std::string &filepath);
  ~BasicShader();

  void Bind() const override;
  void Unbind() const override;

  void SetUniform1i(const std::string &name, int value) override;
  void SetUniform4f(const std::string &name, float *values) override;
  void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix) override;

 private:
  unsigned int rendererId;
  std::string filepath;
  std::unordered_map<std::string, int> uniformLocationCache;

  unsigned int CompileShader(unsigned int type, const std::string &source);
  unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
  ShaderProgramSource ParseShader();

  int GetUniformLocation(const std::string &name);
};
