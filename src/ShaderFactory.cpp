#include "ShaderFactory.h"

#include "Shader/IShader.h"
#include "Shader/BasicShader.h"

ShaderFactory* ShaderFactory::GetInstance()
{
	static ShaderFactory shaderFactoryInstance;
	return &shaderFactoryInstance;
}

IShader* ShaderFactory::GetShader(ShaderType type)
{
	switch(type)
	{
		case ShaderType::BasicShader:
		{
			_shaders.insert(std::pair<ShaderType, IShader*>(
				ShaderType::BasicShader,
				new Shaders::BasicShader("resc/shaders/basic.shader")
			));
		}
		default:
		{
			_shaders.insert(std::pair<ShaderType, IShader*>(
				ShaderType::BasicShader,
				new Shaders::BasicShader("resc/shaders/basic.shader")
			));
		}
	}
	return _shaders.find(type)->second;

	return nullptr;
}
