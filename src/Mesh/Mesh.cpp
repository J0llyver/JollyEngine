#include "Mesh.h"

#include <iostream>

Mesh::Mesh(
	std::vector<float> vertexBuffer,
	std::vector<unsigned int> indexBuffer
) : name(name),
	indexBuffer(indexBuffer),
	vertexBuffer(vertexBuffer)
{}	

Mesh::~Mesh() 
{
	vertexBuffer.clear();
	indexBuffer.clear();
}
