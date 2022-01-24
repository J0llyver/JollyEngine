#include "VertexArray.h"

VertexArray::VertexArray() { glGenVertexArrays(1, &rendererId); }

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &rendererId); }

void VertexArray::AddBuffer(const VertexBuffer &vertexBuffer, const VertexBufferLayout &layout) {
  Bind();
  vertexBuffer.Bind();

  const auto &elements = layout.GetElements();
  unsigned int offset = 0;

  for (uint32_t i = 0; i < elements.size(); ++i) {
    const auto &element = elements[i];
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(),
                          reinterpret_cast<const void*>(offset));
    offset += element.count * VertexBufferLayoutElement::GetSizeOfType(element.type);
  }

  vertexBuffer.Unbind();
}

void VertexArray::Bind() const { glBindVertexArray(rendererId); }

void VertexArray::Unbind() const { glBindVertexArray(0); }
