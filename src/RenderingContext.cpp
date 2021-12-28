#include "RenderingContext.h"

#include "Renderer/OpenGlRenderer.h"

RenderingContext::RenderingContext(RenderingContextType type)
{
	switch(type)
	{
		case RenderingContextType::DirectX:
			// TODO: Implement DirectX Renderer
			break;

		case RenderingContextType::OpenGL:
			renderer = new OpenGlRenderer();
			break;

		case Vulcan:
			// TODO: Implement Vulcan Renderer

		default:
			renderer = new OpenGlRenderer();
	}

	objects = new std::vector<Object*>();
}

void Draw()
{
	renderer.Draw()
}

int RenderingContext::IncludeObject(const Object& object)
{
	int objectId = objects.length();

	objects.insert(std::pair<unsigned int, Object> (objectId, object));

	return objectId;
}

void RenderingContext::ExcludeObject(const unsigned int objectId)
{
	objects.remove(objectId);
}


