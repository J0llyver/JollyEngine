#include "Geometry.h"

Geometry::Geometry(std::vector<float>& vertexBuffer, std::vector<int>& indexBuffer) 
	: vertexBuffer(vertexBuffer),
	indexBuffer(indexBuffer)
{ }

Geometry::~Geometry() 
{
	delete vertexBuffer;
	delete indexBuffer;
}

