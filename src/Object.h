#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "Mesh/Mesh.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <string>

// ToDo: Add pipline for rendering behaviour
// ToDo: Add ppipline fo game behaviour
class Object : Entity
{
public:
	Object(const Mesh& mesh);
	~Object() = default;

	int Scale(const double x);
	int Scale(double xRatio, double yRatio, double zRatio)

	int SetTexture(const std::string& textureLocation);

	int Render() const;

private:
	const Mesh* pMesh;
	const glm::mat4 modelMatrix;
	
	double position[3];
	std::string textureLocation;
};

#endif
