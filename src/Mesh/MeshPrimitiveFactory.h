#ifndef MESH_PRIMITIVES_H
#define MESH_PRIMITIVES_H

#include "MeshPrimitive.h"
#include "Mesh.h"

#include <string>
#include <unordered_map>

class MeshPrimitiveFactory 
{
	public:
		MeshPrimitiveFactory() = default;
		~MeshPrimitiveFactory();

		MeshPrimitiveFactory(MeshPrimitiveFactory const&) = delete;
		void operator=(MeshPrimitiveFactory const&) = delete;

		void LoadPrimitive(MeshPrimitive::Type type, const Mesh* &oPrimitive);

	private:
		void CreatePrimitive(MeshPrimitive::Type type, const Mesh* &oMesh);
		const Mesh* CreateTriangle();
		const Mesh* CreateSquare();

		std::unordered_map<MeshPrimitive::Type,const Mesh> meshMap;
};

#endif

