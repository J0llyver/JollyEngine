#ifndef OBJECT_H
#define OBJECT_H

#include "Mesh/Mesh.h"

#include <string>

// ToDo: Add pipline for rendering behaviour
// ToDo: Add ppipline fo game behaviour
class Object
{
public:
	Object(const Mesh& mesh);
	~Object();

	int SetPosition(const double& x, const double& y, const double& z);
	int SetTexture(const std::string& textureLocation);

	int Render() const;

	double const* GetPosition() const;	
private:
	const Mesh* pMesh;
	
	double position[3];
	std::string textureLocation;
};

#endif
