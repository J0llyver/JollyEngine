#ifndef IENTITY_H
#define IENTITY_H


struct IEntity
{
	virtual int SetPosition(const double& x, const double& y, const double& z) = 0;
	virtual const double* GetPosition() const = 0;	
};

#endif
