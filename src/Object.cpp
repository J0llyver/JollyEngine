#include "Object.h"

#include <fstream>
#include <iostream>

Object::Object(const Mesh& mesh)
{
	this->pMesh = &mesh;

	SetPosition(0.0, 0.0, 0.0);
	SetScale(1.0);
}

int Object::Render() const
{
	// Note: Rendering depends on graphics library used (OpenGL, Vulcan, etc)

	// OpenGL Rendering
	// ToDo: Retrieve Shader
	shader.Bind();
	shader.SetUniformMat4f("u_MVP", modelViewProjectionMatrix);
	shader.SetUniform1i("u_Texture", 0);
	shader.Unbind();

	// ToDo: Implement Vulcan rendering
	return 0;
}

int Object::SetTexture(const std::string& textureLocation)
{
	std::ifstream textureFile(textureLocation.c_str());
	if (!textureFile.good())
	{
		std::cout << "File does not exist: " << textureLocation << std::endl;
		return -1;
	}

	this->textureLocation = textureLocation;

	return 0;
}

int Object::Scale(double ratio)
{
	modelMatrix = Scale(ratio, ratio, ratio);
}

int Object::Scale(double xRatio, double yRatio, double zRatio)
{
	modelMatrix = glm::scale(modelMatrix, glm::vec3(xRatio, yRatio, zRatio));
}

