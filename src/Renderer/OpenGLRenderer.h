#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "IRenderer.h"
#include "../Shader/IShader.h"

#include <vector>

class OpenGLRenderer : IRenderer {
public:
	void Clear() const override;
	void Draw(
		const std::vector<float> vertexArray,
		const std::vector<unsigned int> indexBufer,
		const IShader& shader
	) const override;
};

#endif
