#ifndef GEOMETRY_STORE_H
#define GEOMETRY_STORE_H

#include "../Geometry.h"
#include "../Primitives/GeometryPrimitiveType.h"

#include <string>
#include <unordered_map>

/*
 * A class to store, load and delete Geometry.
 * Basically a GeometryDatabase.
 * This class is not inteded to be used for rendering
 */
class GeometryStore
{
	public: 
		GeometryStore();
		~GeometryStore();

		void LoadPrimitive(GeometryPrimitiveType type, const Geometry* oPrimitive);

	private:
		std::unordered_map<std::string, Geometry> geometryMap;
		std::unordered_map<std::string, Geometry>::const_iterator geometryMapIterator;
		
};

#endif
