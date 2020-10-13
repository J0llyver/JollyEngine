#include "Entity.h"

double const* Entity::GetPosition() const
{
	return this->position;
}

Entity::SetPostition(const double& x, const double& y, const double& t)
{
	this->position[0] = x;
	this->position[1] = y;
	this->position[2] = z;
}
