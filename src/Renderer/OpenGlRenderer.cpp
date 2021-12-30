#include "OpenGlRenderer.h"

#include <iostream>

#include "src/IndexBuffer.h"
#include "src/VertexArray.h"
#include "src/VertexBuffer.h"

void OpenGlRenderer::Clear() const { glClear(GL_COLOR_BUFFER_BIT); }

// This draw call needs to render all objects
void OpenGlRenderer::Draw(const Mesh &mesh, std::shared_ptr<Shader> &shader) const {
  VertexBufferLayout layout;
  layout.Push(GL_FLOAT, 2);
  layout.Push(GL_FLOAT, 2);

  VertexBuffer vertexBuffer(mesh.vertices, mesh.numberOfVertices * 3 * sizeof(float));

  VertexArray vertexArray;
  vertexArray.AddBuffer(vertexBuffer, layout);

  IndexBuffer indexBuffer(mesh.indices, mesh.numberOfIndices);

  vertexArray.Bind();
  indexBuffer.Bind();

  shader->Bind();

  glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);

  vertexBuffer.Unbind();
  vertexArray.Unbind();
  indexBuffer.Unbind();

  shader->Unbind();
}