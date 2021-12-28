#ifndef MESH_H
#define MESH_H

#include <vector>

#include <iostream>
class Mesh 
{
	public:
		Mesh(
			std::vector<float> vertexBuffer, 
			std::vector<unsigned int> indexBuffer
		);
		~Mesh();

		const std::vector<float> GetVertexBuffer() const { return vertexBuffer; }
		const std::vector<unsigned int> GetIndexBuffer() const { return indexBuffer; }

	private:
		std::vector<float> vertexBuffer;
		std::vector<unsigned int> indexBuffer;
		std::string name;
};

#endif
