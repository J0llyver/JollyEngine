#include "MeshStore.h"

#include "MeshPrimitiveFactory.h"

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

	auto geometryMapIterator = geometryMap.find(serializedType);

	if (geometryMapIterator != geometryMap.end())
	{
		oPrimitive = &(geometryMapIterator->second);
	}
	else 
	{
		MeshPrimitiveFactory::CreatePrimitive(type, oPrimitive);
	}
}
