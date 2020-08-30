#include "MeshPrimitiveFactory.h"

#include "Mesh.h"

namespace
{
	Mesh* CreateTriangle()
	{
		std::vector<float> vertexBuffer = 
		{
			-0.5, 0.0, 0.0,
			0.5, 0.0, 0.0,
			0.0, 1.0, 0.0
		};

		std::vector<int> indexBuffer = { 0, 1, 2 };

		Mesh* triangle = new Mesh(vertexBuffer, indexBuffer);	

		return triangle;
	}
	
	Mesh* CreateSquare()
	{
		std::vector<float> vertexBuffer = 
		{
			-0.5, -0.5, 0.0,
			0.5, -0.5, 0.0,
			0.5, 0.5, 0.0,
			-0.5, 0.5, 0.0
		};

		std::vector<int> indexBuffer = { 0, 1, 2, 2, 3, 0 };

		Mesh* square = new Mesh(vertexBuffer, indexBuffer);	

		return square;
	}
}

MeshPrimitiveFactory::MeshPrimitiveFactory() {}

void MeshPrimitiveFactory::CreatePrimitive(MeshPrimitiveType type, const Mesh* oMesh)
{
	switch(type)
	{
		case Square:
				oMesh = CreateSquare();
			break;

		case Triangle:
				oMesh = CreateTriangle();
			break;

		default:
				oMesh = CreateTriangle();	
	}
}

