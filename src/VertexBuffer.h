#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <vector>

class VertexBuffer {
 private:
  unsigned int rendererID;

 public:
  // VertexBuffer(const void* vertexBuffer, unsigned int &size);
  VertexBuffer(const std::vector<float> &vertexBuffer, const unsigned int &size);

  ~VertexBuffer();

  void Bind() const;
  void Unbind() const;
};

#endif
