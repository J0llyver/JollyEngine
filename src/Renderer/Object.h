#ifndef OBJECT_H
#define OBJECT_H

#include "Entity.h"
#include "Mesh/Mesh.h"
#include "Renderer/IRenderer.h"

#include "glm/gtc/matrix_transform.hpp"

#include <string>

// ToDo: Add pipline for rendering behaviour
// ToDo: Add ppipline fo game behaviour
class Object : Entity
{
public:
	Object(const Mesh& mesh);
	~Object() = default;

	inline void Scale(const double x);
	void Scale(double xRatio, double yRatio, double zRatio);

	int SetTexture(const std::string& textureLocation);

	int Render(IRenderer renderer) const;

private:
	const Mesh* pMesh;
	glm::mat4 modelMatrix;
	
	std::string textureLocation;
};

#endif
