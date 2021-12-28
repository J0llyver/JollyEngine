#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "../Shader/IShader.h"
#include "../VertexArray.h"
#include "../VertexBuffer.h"
#include "IRenderer.h"

#include <vector>

class OpenGlRenderer : IRenderer 
{
public:
	void Clear() const override;
	void Draw(
		const std::vector<float> vertexArray,
		const std::vector<unsigned int> indexBufer,
		const IShader& shader
	) const override;

	void BindVertexBuffer(const std::vector vertexBuffer, const VertexBufferLaout layout);
	void UnbindVertexBuffer(/* TODO: poperly define method */)

private:
	std::unordered_map<unsigned int, VertexBuffer> vertexBuffers;
	
	VertexArray vertexArray;
	IndexBuffer indexBuffer;
};

#endif
