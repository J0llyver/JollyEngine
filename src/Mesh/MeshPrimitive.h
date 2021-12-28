#pragma once

#include<string>

namespace MeshPrimitive
{
	enum Type 
	{
		Square = 0,
		Triangle = 1	
	};

	std::string SerializeType(Type type)
	{
		switch(type)
		{
			case Type::Square:
				return "Square";

			case Type::Triangle:
				return "Triangle";
		}
	}
}
