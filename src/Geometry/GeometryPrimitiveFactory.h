#ifndef GEOMETRY_PRIMITIVES_H
#define GEOMETRY_PRIMITIVES_H

#include "GeometryPrimitiveType.h"
#include "../Geometry.h"

class GeometryPrimitiveFactory 
{
	private:
		GeometryPrimitiveFactory() {}

	public:
		GeometryPrimitiveFactory(GeometryPrimitiveFactory const&) = delete;
		void operator=(GeometryPrimitiveFactory const&) = delete;

		static void CreatePrimitive(GeometryPrimitiveType type, const Geometry* oGeometry);
};

#endif

