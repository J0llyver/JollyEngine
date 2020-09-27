#ifndef MESH_PRIMITIVES_H
#define MESH_PRIMITIVES_H

#include "MeshPrimitiveType.h"
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

		void LoadPrimitive(MeshPrimitiveType type, const Mesh* &oPrimitive);

	private:
		void CreatePrimitive(MeshPrimitiveType type, const Mesh* &oMesh);
		const Mesh* CreateTriangle();
		const Mesh* CreateSquare();

		std::unordered_map<MeshPrimitiveType,const Mesh> meshMap;
};

#endif

