#include "Mesh.h"

#include <iostream>

Mesh::Mesh(std::vector<float> vertexBuffer, std::vector<unsigned int> indexBuffer) 
{ 
	this->vertexBuffer = vertexBuffer;
	this->indexBuffer = indexBuffer;
}

Mesh::~Mesh() 
{
	vertexBuffer.clear();
	indexBuffer.clear();
}
