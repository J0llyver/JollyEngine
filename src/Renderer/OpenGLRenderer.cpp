#include "OpenGLRenderer.h"

#include <iostream>

void OpenGLRenderer::Clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::Draw(const std::vector<float> vertices, const std::vector<unsigned int> indices, const IShader& shader) const
{
	// Ojects with a single isntance for each rendering context
	VertexBufferLayout layout;
	layout.Push(GL_FLOAT, 2);
	layout.Push(GL_FLOAT, 2);

	VertexArray vertexArray;
	IndexBuffer indexBuffer(&indices[0], indices.size());
	//-------------

	VertexBuffer vertexBuffer(&vertices[0], vertices.size() * sizeof(float));

	va.AddBuffer(vertexBuffer, layout);
	vertexArray.Bind();
	indexBuffer.Bind();
    shader.Bind();


    glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);

	vertexBuffer.Unbind();
	vertexArray.Unbind();
	indexBuffer.Unbind();	

    shader.Unbind();
}
