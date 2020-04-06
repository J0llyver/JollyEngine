#include "../Geometry.h"

namespace
{
	Geometry* CreateTriangle()
	{
		std::vector<float> vertexBuffer = 
		{
			-0.5, 0.0, 0.0,
			0.5, 0.0, 0.0,
			0.0, 1.0, 0.0
		};

		std::vector<int> indexBuffer = { 0, 1, 2 };

		Geometry triangle = new Geometry(vertexBuffer, indexBuffer);	

		return triangle;
	}
	
	Geometry* CreateSquare()
	{
		std::vector<float> vertexBuffer = 
		{
			-0.5, -0.5, 0.0,
			0.5, -0.5, 0.0,
			0.5, 0.5, 0.0,
			-0.5, 0.5, 0.0
		};

		std::vector<int> indexBuffer = { 0, 1, 2, 2, 3, 0 };

		Geometry square = new Geometry(vertexBuffer, indexBuffer);	

		return &square;
	}
}

GeometryPrimitiveFactory::GeometryPrimitiveFactory() {}

void GeometryPrimitiveFactory::CreatePrimitive(GeometryPrimitiveType type, const Geometry* oGeometry)
{
	switch(type)
	{
		case Sqare:
				oGeometry = CreateSquare();
			break;

		case Triangle:
				oGeometry = CreateTriangle();
			break;

		default:
				oGeometry = CreateTriangle();	
	}
}

#endif

