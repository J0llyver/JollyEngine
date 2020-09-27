#include "MeshPrimitiveFactory.h"

MeshPrimitiveFactory::~MeshPrimitiveFactory() { meshMap.clear(); }

void MeshPrimitiveFactory::LoadPrimitive(MeshPrimitiveType type, const Mesh* &oPrimitive)
{
	auto meshMapIterator = meshMap.find(type);

	if (meshMapIterator != meshMap.end())
	{
		oPrimitive = &(meshMapIterator->second);
	}
	else 
	{
		CreatePrimitive(type, oPrimitive);
	}
}

void MeshPrimitiveFactory::CreatePrimitive(MeshPrimitiveType type, const Mesh* &oMesh)
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
			break;
	}
}

const Mesh* MeshPrimitiveFactory::CreateTriangle()
{
	std::vector<float> vertexBuffer = 
	{
		-0.5, 0.0, 0.0,
		0.5, 0.0, 0.0,
		0.0, 1.0, 0.0
	};

	std::vector<unsigned int> indexBuffer = { 0, 1, 2 };

	meshMap.insert(std::pair(MeshPrimitiveType::Triangle, Mesh(vertexBuffer, indexBuffer)));

	return &(meshMap.find(MeshPrimitiveType::Triangle)->second);
}

const Mesh* MeshPrimitiveFactory::CreateSquare()
{
	std::vector<float> vertexBuffer = 
	{
		//-0.5, -0.5, 0.0,
		//0.5, -0.5, 0.0,
		//0.5, 0.5, 0.0,
		//-0.5, 0.5, 0.0
		0.0f, 0.0f, 0.0f, 0.0f,
		100.0f, 0.0f, 1.0f, 0.0f,
		100.0f, 100.0f, 1.0f, 1.0f,
		0.0f, 100.0f, 0.0f, 1.0f
	};
	std::vector<unsigned int> indexBuffer = { 0, 1, 2, 2, 3, 0 };

	meshMap.insert(std::pair(MeshPrimitiveType::Square, Mesh(vertexBuffer, indexBuffer)));

	return &(meshMap.find(MeshPrimitiveType::Square)->second);
}
