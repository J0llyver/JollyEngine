#include "MeshPrimitiveFactory.h"

MeshPrimitiveFactory::~MeshPrimitiveFactory() { meshMap.clear(); }

void MeshPrimitiveFactory::LoadPrimitive(MeshPrimitive::Type type, const Mesh* &oPrimitive)
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

void MeshPrimitiveFactory::CreatePrimitive(MeshPrimitive::Type type, const Mesh* &oMesh)
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

	meshMap.insert(std::pair(MeshPrimitive::Type::Triangle, Mesh(vertexBuffer, indexBuffer)));

	return &(meshMap.find(MeshPrimitive::Type::Triangle)->second);
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

	meshMap.insert(std::pair(MeshPrimitive::Type::Square, Mesh(vertexBuffer, indexBuffer)));

	return &(meshMap.find(MeshPrimitive::Type::Square)->second);
}
