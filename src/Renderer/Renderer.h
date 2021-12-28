#ifndef IRENDERER_H
#define IRENDERER_H

#include "../IndexBuffer.h"
#include "../VertexArray.h"
#include "../Shader/IShader.h"

#include <vector>

class IRenderer {
public:
	virtual void Clear() const = 0;
	virtual void Draw(
		const std::vector<float> vertexArray,
		const std::vector<unsigned int> indexBufer,
		const IShader& shader
	) const = 0;
};

#endif
