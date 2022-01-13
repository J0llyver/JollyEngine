#include "ShaderFactory.h"

#include <filesystem>
#include <iostream>

#include "Shader/BasicShader.h"

std::shared_ptr<ShaderFactory> ShaderFactory::GetInstance() {
  static std::shared_ptr<ShaderFactory> shaderFactoryInstance = std::shared_ptr<ShaderFactory>(new ShaderFactory());
  return shaderFactoryInstance;
}

std::shared_ptr<Shader> ShaderFactory::GetShader(const ShaderType &type) {
  switch (type) {
    case ShaderType::Basic: {
      shaders.insert(std::make_pair(static_cast<uint32_t>(ShaderType::Basic),
                                    std::make_shared<BasicShader>("resc/shaders/basic.shader")));
      break;
    }
    default: {
      shaders.insert(std::make_pair(static_cast<uint32_t>(ShaderType::Basic),
                                    std::make_shared<BasicShader>("resc/shaders/basic.shader")));
    }
  }

  return shaders[type];
}
