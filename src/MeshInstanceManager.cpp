#include "Mesh/MeshPrimitiveFactory.h"
#include "MeshInstanceManager.h"

bool MeshInstanceManager::CreateMeshInstance(MeshPrimitive::Type type)
{
	auto insertionResult = meshInstanceMonitors.insert(
		std::pair<std::string, MeshInstanceMonitor>(
			MeshPrimitive::SerializeType(type),
			monitor
	));

	if (insertionResult->second)
	{
		// ToDo: Load mesh primitive into vertex and index buffer
		//MeshPrimitiveFactory::GetInstance()->

		// ToDo: Instantiate MeshInstance
	}

	insertionResult->first->instanceCount++;
}

bool MeshInstanceManager::CreateMeshInstance(std::string meshId)
{
	MeshInstanceMonitor monitor;

	auto insertionResult = meshInstanceMonitors.insert(
		std::pair<std::string, MeshInstanceMonitor>(meshId, monitor)
	);

	if (insertionResult->second)
	{
		// ToDo: Load mesh into vertex and index buffer
		// ToDo: Instantiate MeshInstance
	}
	
	insertionResult->first->instanceCount++;
}

bool MeshInstanceManager::DeleteMeshInstance(MeshPrimitive::Type type)
{
	DeleteMeshInstance(MeshPrimitive::SerializeType(type));
}

bool MeshInstanceManager::DeleteMeshInstance(std::string meshId)
{
	auto iterator = meshInstanceMontiors.find(meshId);

	iterator->second.instanceCount--;
	
	if (iterator->second.instanceCount == 0)
	{
		meshInstanceMonitors.erase(iterator);
	}
}
