#ifndef ENTITY_H
#define ENTITY_H

#include "IEntity.h"

class Entity : IEntity
{

public:
	Entity();
	~Entity();

	void GetPostion() const override;
	void SetPostition(const double& x, const double& y, const double& t) override;

private:
	double position[3];

};

#endif
