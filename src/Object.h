#ifndef OBJECT_H
#define OBJECT_H

#include "Mesh/Mesh.h"

class Object
{
public:
	Object(const Mesh& mesh);
	~Object();

	SetPosition(const double& x, const double& y, const double& z);

	const double* GetPosition();	
private:
	Mesh* mesh;
	
	double position[3];

	// ToDo: Include Texture			
};

#endif
