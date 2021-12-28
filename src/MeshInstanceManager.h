#ifndef MESHINSTANCEMANAGER_H
#define MESHINSTANCEMANAGER_H

#include "Mesh/MeshPrimitive.h"

#include <vector>
#include <string>

struct MeshInstance
{
	unsigned int* indexBufferStart;
	unsigned int indexCount;

	float* vertexBufferStart;
	unsigned int vertexCount;
}

class MeshInstanceManager
{
public:
	MeshInstanceManager() = default;
	~MeshInstanceManager() = default;

	const float* GetVertexBuffer() const { return &(vertexBuffer[0]) }
	const unsigned int* GetIndexBuffer() const { return &(indexBuffer[0]) }

	bool CreateMeshInstance(MeshPrimitive::Type type);
	bool CreateMeshInstance(std::string meshId);

	bool DeleteMeshInstance(MeshPrimitive::Type type);
	bool DeleteMeshInstance(std::string meshId);

private:
	struct MeshInstanceMonitor
	{
		unsigned int instanceCount;
		MeshInstance meshInstance;
	}

	std::vector<float> vertexBuffer;
	std::vector<unsigned int> indexBuffer;

	std::unordered_map<std::string, MeshInstanceMonitor> meshInstanceMonitors;
}

#endif
