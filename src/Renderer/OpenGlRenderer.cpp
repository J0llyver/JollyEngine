#include "OpenGlRenderer.h"

#include <iostream>

void OpenGlRenderer::Clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

// This draw call needs to render all objects
void OpenGlRenderer::Draw(const std::vector<float> vertices, const std::vector<unsigned int> indices, const IShader& shader) const
{
	// Ojects with a single isntance for each rendering context
	VertexBufferLayout layout;
	layout.Push(GL_FLOAT, 2);
	layout.Push(GL_FLOAT, 2);

	VertexArray vertexArray;
	IndexBuffer indexBuffer(&indices[0], indices.size());
	//-------------

	VertexBuffer vertexBuffer(&vertices[0], vertices.size() * sizeof(float));

	vertexArray.Bind();
	indexBuffer.Bind();
    shader.Bind();


    glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);

	vertexBuffer.Unbind();
	vertexArray.Unbind();
	indexBuffer.Unbind();	

    shader.Unbind();
}

void OpenGlRenderer::BindVertexBuffer(const std::vector vertexBuffer, const VertexBufferLaout layout)
{
	va.AddBuffer(vertexBuffer, layout);
}

void OpenGlRenderer::UnbindVertexBuffer(/* TODO: poperly define method */)
{
}

