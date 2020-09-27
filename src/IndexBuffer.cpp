#include "IndexBuffer.h"

#include "OpenGLRenderer.h"

IndexBuffer::IndexBuffer(const std::vector<unsigned int>* indexBuffer, unsigned int count)
{
	this->count = count;
	glGenBuffers(1, &rendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indexBuffer, GL_STATIC_DRAW);
}

IndexBuffer::IndexBuffer(const unsigned int* indexBuffer, unsigned int count)
{
	this->count = count;
    glGenBuffers(1, &rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indexBuffer, GL_STATIC_DRAW);
}


IndexBuffer::~IndexBuffer(){
	glDeleteBuffers(1, &rendererID);
}

void IndexBuffer::Bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
}

void IndexBuffer::Unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
