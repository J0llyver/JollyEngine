#ifndef MESH_STORE_H
#define MESH_STORE_H

#include "../Mesh.h"
#include "../Primitives/MeshPrimitiveType.h"

#include <string>
#include <unordered_map>

/*
 * A class to store, load and delete Mesh.
 * Basically a MeshDatabase.
 * This class is not inteded to be used for rendering
 */
class MeshStore
{
	public: 
		MeshStore();
		~MeshStore();

		void LoadPrimitive(MeshPrimitiveType type, const Mesh* oPrimitive);

	private:
		std::unordered_map<std::string, Mesh> geometryMap;
		std::unordered_map<std::string, Mesh>::const_iterator geometryMapIterator;
		
};

#endif
