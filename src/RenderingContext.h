#ifndef RENDERINGCONTEXT_H
#define RENDERINGCONTEXT_H

#include "Object.h"
#include "Renderer/IRenderer.h"

#include <unordered_map>

enum RenderingContextType
{
	DirectX = 0,
	OpenGL = 1,
	Vulcan = 2
}

class RenderingContext 
{
public:
	RenderingContext(RenderingContextType type);
	~RenderingContext() = default;

	void Draw();

	int IncludeObject(const Object& object);
	void ExcludeObject(const unsigned int objectId);

private: 
	IRenderer renderer;
	std::unordered_map<unsigned int, Object*> objects;
}

#endif
