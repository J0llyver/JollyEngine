#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <string>

// ToDo: implement methods in Geometry.cpp, also Constructor and Destructor
class Geometry 
{
	public:
		Geometry(
			std::vector<float>& vertexBuffer, 
			std::vector<int>& indexBuffer
		);
		~Geometry(); // ToDo: Delete vertexBuffer and indexBuffer

		float* GetVertexBuffer() const { return vertexBuffer; }
		int* GetIndexBuffer() const { return indexBuffer; }

	private:
		std::vector<float>* vertexBuffer;
		std::vector<int>* indexBuffer;
};

#endif
