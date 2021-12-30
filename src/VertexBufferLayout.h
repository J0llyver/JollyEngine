#pragma once

#include <GL/glew.h>

#include <vector>

struct VertexBufferLayoutElement {
  unsigned int type;
  unsigned int count;
  unsigned char normalized;

  static unsigned int GetSizeOfType(unsigned int type) {
    switch (type) {
      case GL_FLOAT: {
        return 4;
      }
      case GL_UNSIGNED_INT: {
        return 4;
      }
      case GL_UNSIGNED_BYTE: {
        return 1;
      }
    }
    return 0;
  }
};

class VertexBufferLayout {
 public:
  VertexBufferLayout() : stride(0) {}

  ~VertexBufferLayout();

  void Push(unsigned int type, unsigned int count);

  inline const std::vector<VertexBufferLayoutElement> GetElements() const { return elements; }
  inline unsigned int GetStride() const { return stride; }

 private:
  std::vector<VertexBufferLayoutElement> elements;
  unsigned int stride;
};
