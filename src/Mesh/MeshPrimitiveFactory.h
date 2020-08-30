#ifndef MESH_PRIMITIVES_H
#define MESH_PRIMITIVES_H

#include "MeshPrimitiveType.h"
#include "Mesh.h"

class MeshPrimitiveFactory 
{
	private:
		MeshPrimitiveFactory();

	public:
		MeshPrimitiveFactory(MeshPrimitiveFactory const&) = delete;
		void operator=(MeshPrimitiveFactory const&) = delete;

		static void CreatePrimitive(MeshPrimitiveType type, const Mesh* oMesh);
};

#endif

