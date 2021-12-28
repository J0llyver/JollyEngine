#pragma once

#include "Shader/Shader.h"

#include <unordered_map>

enum ShaderType {
	BasicShader = 0
};

// Note: This Singleton is not thread save.
class ShaderFactory {

private:
	ShaderFactory() = default;
	~ShaderFactory() = default;

	std::unordered_map<ShaderType, IShader*> _shaders;

public:
	ShaderFactory(ShaderFactory* other) = delete;
	void operator=(const ShaderFactory &) = delete;

	static ShaderFactory* GetInstance();

	IShader* GetShader(ShaderType type);

};
