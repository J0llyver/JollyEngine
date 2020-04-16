#include "Object.h"

#include <fstream>
#include <iostream>

Object::Object(const Mesh& mesh)
{
	this->pMesh = &mesh;
	this->position[0] = 0.0;
	this->position[1] = 0.0;
	this->position[2] = 0.0;
}

Object::~Object()
{
}

int Object::SetPosition(const double& x, const double& y, const double& z)
{
	this->position[0] = x;
	this->position[1] = y;
	this->position[2] = z;

	return 0;
}

int Object::SetTexture(const std::string& textureLocation)
{
	std::ifstream textureFile(textureLocation.c_str());
	if (!textureFile.good())
	{
		std::cout << "File does not exist: " << textureLocation << std::endl;
		return -1;
	}

	this->textureLocation = textureLocation;

	return 0;
}

int Object::Render() const
{
	return 0;
}

double const* Object::GetPosition() const
{
	return this->position;
}

