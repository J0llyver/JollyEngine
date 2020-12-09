#include "OpenGLRenderer.h"

#include <iostream>

void OpenGLRenderer::Clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::Draw(const VertexArray& vertexArray, const IndexBuffer&  indexBuffer, const IShader& shader) const {
    shader.Bind();
	vertexArray.Bind();
	indexBuffer.Bind();

    glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);

    shader.Unbind();
}
