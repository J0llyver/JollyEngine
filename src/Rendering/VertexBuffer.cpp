#include "VertexBuffer.h"

#include <GL/glew.h>

VertexBuffer::VertexBuffer(const void* vertexBuffer, const uint32_t size) {
  this->numberOfVertices = size;
  glGenBuffers(1, &rendererID);
  glBindBuffer(GL_ARRAY_BUFFER, rendererID);
  glBufferData(GL_ARRAY_BUFFER, size, vertexBuffer, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &rendererID); }

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, rendererID); }

void VertexBuffer::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }
