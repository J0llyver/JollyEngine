#ifndef ISHADER_H
#define ISHADER_H

#include "glm/glm.hpp"

#include <string>

struct IShader
{
	virtual void Bind() const = 0;
	virtual void Unbind() const = 0;

	virtual void SetUniform1i(const std::string& name, int value) = 0;
	virtual void SetUniform4f(const std::string& name, float* values) = 0;
	virtual void SetUniformMat4f(const std::string& name, const glm::mat4& matrix) = 0;
};

#endif
