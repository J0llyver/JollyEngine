#ifndef ENTITY_H
#define ENTITY_H

#include "IEntity.h"

class Entity : IEntity
{

public:
	Entity();
	~Entity() = default;

	const double* GetPosition() const;
	void SetPostition(const double& x, const double& y, const double& t);

protected:
	double position[3];

};

#endif
