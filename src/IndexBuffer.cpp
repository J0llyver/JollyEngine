#include "IndexBuffer.h"

#include <GL/glew.h>

IndexBuffer::IndexBuffer(const std::vector<uint32_t> *indexBuffer, uint32_t size) {
  this->numberOfIndices = size;
  glGenBuffers(1, &rendererID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, numberOfIndices * sizeof(uint32_t), indexBuffer, GL_STATIC_DRAW);
}

IndexBuffer::IndexBuffer(const uint32_t *indexBuffer, uint32_t size) {
  this->numberOfIndices = size;
  glGenBuffers(1, &rendererID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, numberOfIndices * sizeof(uint32_t), indexBuffer, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &rendererID); }

void IndexBuffer::Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID); }

void IndexBuffer::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
