#include "GeometryStore.h"
#include "../Primitives/GeometryPrimitiveFactory.h"

namespace 
{
	std::string SerializeGeometryPrimitiveType(GeometryPrimitiveType type)
	{
		std::string serializedType;
		switch(type)
		{
			case GeometryPrimitiveType::Square:
				serializedType = "Square";
				break;

			case GeometryPrimitiveType::Triangle:
				serializedType = "Triangle";
				break;
		}
		return serializedType;
	}
}

GeometryStore::GeometryStore() {}
GeometryStore::~GeometryStore() {}

void GeometryStore::LoadPrimitive(GeometryPrimitiveType type, const Geometry* oPrimitive)
{
	std::string serializedType = SerializeGeometryPrimitiveType(type);

	geometryMapIterator = geometryMap.find(serializedType);

	if (geometryMapIterator != geometryMap.end())
	{
		oPrimitive = &(geometryMapIterator->second);
	}
	else 
	{
		GeometryPrimitivesFactory::CreatePrimitive(type, oPrimitive);
	}
}
