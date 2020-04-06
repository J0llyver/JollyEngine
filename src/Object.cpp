#include "Object.h"

// ToDo: Implement Object Class

Object::Object(const Mesh& mesh)
{
	this.mesh = &mesh;
	this.position = new double[3]{ 0, 0, 0 };
}

Object::~Object()
{
	delete this.position;
}

Object::SetPosition(const double& x, const double& y, const double& z)
{
	this.position[0] = x;
	this.position[1] = y;
	this.position[2] = z;
}

const double* Object::GetPosition()
{
	return this.position;
}

