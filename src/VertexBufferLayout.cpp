#include "VertexBufferLayout.h"

VertexBufferLayout::~VertexBufferLayout() {}

void VertexBufferLayout::Push(unsigned int type, unsigned int count){

	elements.push_back({ type, count, GL_FALSE });
	stride += count * VertexBufferLayoutElement::GetSizeOfType(type);
}