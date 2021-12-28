#pragma once

#include "src/Shader/Shader.h"
#include "src/VertexArray.h"
#include "src/VertexBuffer.h"
#include "Renderer.h"

#include <vector>

class OpenGlRenderer : IRenderer 
{
public:
	void Clear() const override;
	void Draw(const std::vector<float> &vertexArray, const std::vector<unsigned int> &indexBufer, const IShader& &shader) const override;

	void BindVertexBuffer(const std::vector &vertexBuffer, const VertexBufferLaout &layout);
	void UnbindVertexBuffer(/* TODO: poperly define method */)

private:
	std::unordered_map<unsigned int, VertexBuffer> vertexBuffers;
	
	VertexArray vertexArray;
	IndexBuffer indexBuffer;
};

