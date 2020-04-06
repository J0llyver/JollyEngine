#include "MeshStore.h"
#include "../Primitives/MeshPrimitiveFactory.h"

namespace 
{
	std::string SerializeMeshPrimitiveType(MeshPrimitiveType type)
	{
		std::string serializedType;
		switch(type)
		{
			case MeshPrimitiveType::Square:
				serializedType = "Square";
				break;

			case MeshPrimitiveType::Triangle:
				serializedType = "Triangle";
				break;
		}
		return serializedType;
	}
}

MeshStore::MeshStore() {}
MeshStore::~MeshStore() {}

void MeshStore::LoadPrimitive(MeshPrimitiveType type, const Mesh* oPrimitive)
{
	std::string serializedType = SerializeMeshPrimitiveType(type);

	meshMapIterator = meshMap.find(serializedType);

	if (meshMapIterator != meshMap.end())
	{
		oPrimitive = &(meshMapIterator->second);
	}
	else 
	{
		MeshPrimitivesFactory::CreatePrimitive(type, oPrimitive);
	}
}
