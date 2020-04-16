#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>

// ToDo: implement methods in Mesh.cpp, also Constructor and Destructor
class Mesh 
{
	public:
		Mesh(
			std::vector<float>& vertexBuffer, 
			std::vector<int>& indexBuffer
		);
		~Mesh(); // ToDo: Delete vertexBuffer and indexBuffer

		std::vector<float>* GetVertexBuffer() const { return vertexBuffer; }
		std::vector<int>* GetIndexBuffer() const { return indexBuffer; }

	private:
		std::vector<float>* vertexBuffer;
		std::vector<int>* indexBuffer;
};

#endif
