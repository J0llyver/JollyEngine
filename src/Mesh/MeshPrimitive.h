#ifndef MESH_PRIMITIVE_TYPE_H
#define MESH_PRIMITIVE_TYPE_H

namespace MeshPrimitive
{
	enum Type 
	{
		Square = 0,
		Triangle = 1	
	};

	string SerializeType(Type type)
	{
		switch(type)
		{
			case Type::Square:
				return "Square";

			case Type::Triangle
				return "Triangle";
		}
	}
}

#endif
