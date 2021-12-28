#pragma once

#include "src/IndexBuffer.h"
#include "src/Shader/Shader.h"
#include "src/VertexArray.h"

#include <vector>

class IRenderer {
public:
	virtual void Clear() const = 0;
	virtual void Draw(const std::vector<float> &vertexArray, const std::vector<unsigned int> &indexBufer, const Shader& &shader) const = 0;
};
