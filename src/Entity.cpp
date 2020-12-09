#include "Entity.h"

Entity::Entity()
{
	this->position[0] = 0.0;
	this->position[1] = 0.0;
	this->position[2] = 0.0;
}

const double* Entity::GetPosition() const
{
	return &(this->position[0]);
}

void Entity::SetPostition(const double& x, const double& y, const double& z)
{
	this->position[0] = x;
	this->position[1] = y;
	this->position[2] = z;
}
