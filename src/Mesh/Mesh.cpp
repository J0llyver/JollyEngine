#include "Mesh.h"

Mesh::Mesh(std::vector<float>& vertexBuffer, std::vector<int>& indexBuffer) 
	: vertexBuffer(vertexBuffer),
	indexBuffer(indexBuffer)
{ }

Mesh::~Mesh() 
{
	delete vertexBuffer;
	delete indexBuffer;
}

