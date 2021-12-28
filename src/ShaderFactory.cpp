#include "ShaderFactory.h"

#include "Shader/BasicShader.h"
#include "Shader/Shader.h"

ShaderFactory *ShaderFactory::GetInstance() {
  static ShaderFactory shaderFactoryInstance;
  return &shaderFactoryInstance;
}

std::shared_ptr<Shader> ShaderFactory::GetShader(const ShaderType &type) {
  switch (type) {
    case ShaderType::BasicShader: {
      shaders.insert(std::make_pair(static_cast<uint32_t>(ShaderType::BasicShader),
                                    Shaders::BasicShader("resc/shaders/basic.shader")));
      break;
    }
    default: {
      shaders.insert(std::make_pair(static_cast<uint32_t>(ShaderType::BasicShader),
                                    Shaders::BasicShader("resc/shaders/basic.shader")));
    }
  }

  return shaders[type];
}
