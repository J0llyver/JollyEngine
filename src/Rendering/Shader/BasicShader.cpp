#include "BasicShader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

BasicShader::BasicShader(const std::string &filepath) {
  this->filepath = filepath;
  this->rendererId = 0;

  ShaderProgramSource source = ParseShader();
  rendererId = CreateShader(source.VertexSource, source.FragmentSource);
}

BasicShader::~BasicShader() { glDeleteProgram(rendererId); }
void BasicShader::Bind() const {
  if (rendererId != 0) {
    glUseProgram(rendererId);
  } else {
    std::logic_error("rendererId in Shader is 0!");
  }
}

void BasicShader::Unbind() const { glUseProgram(0); }

unsigned int BasicShader::CompileShader(unsigned int type, const std::string &source) {
  unsigned int id = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);

  if (result == 0) {  // GL_FALSE == 0
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

    // Use this to debug failing shader compilation. The message can be printed using std::cout.
    // char* message = (char*)alloca(length * sizeof(char));
    // glGetShaderInfoLog(id, length, &length, message);

    std::logic_error("Failed to compile shader");

    glDeleteShader(id);

    return 0;
  }

  return id;
}

unsigned int BasicShader::CreateShader(const std::string &vertexShader, const std::string &fragmentShader) {
  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}

ShaderProgramSource BasicShader::ParseShader() {
  std::ifstream stream(filepath);

  enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;
  while (getline(stream, line)) {
    if (line.find("#shader") != std::string::npos) {
      if (line.find("vertex") != std::string::npos) {
        type = ShaderType::VERTEX;
      } else if (line.find("fragment") != std::string::npos) {
        type = ShaderType::FRAGMENT;
      }
    } else {
      ss[(int)type] << line << '\n';
    }
  }

  return {ss[0].str(), ss[1].str()};
}

void BasicShader::SetUniform1i(const std::string &name, int value) { glUniform1i(GetUniformLocation(name), value); }

void BasicShader::SetUniform4f(const std::string &name, float* values) {
  glUniform4f(GetUniformLocation(name), values[0], values[1], values[2], values[3]);
}

void BasicShader::SetUniformMat4f(const std::string &name, const glm::mat4 &matrix) {
  glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

int BasicShader::GetUniformLocation(const std::string &name) {
  int location;

  if (uniformLocationCache.find(name) != uniformLocationCache.end()) {
    location = uniformLocationCache[name];
  } else {
    location = glGetUniformLocation(rendererId, name.c_str());
    if (location == -1) {
      std::logic_error("Uniform" + name + " does not exist.");
    }
    uniformLocationCache[name] = location;
  }

  return location;
}
