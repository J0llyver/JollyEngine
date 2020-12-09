#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <GL/glew.h>

#include "../IndexBuffer.h"
#include "../VertexArray.h"
#include "../Shader/IShader.h"

class OpenGLRenderer{
public:
	
	void Clear() const;

	void Draw(
		const VertexArray& vertexArray,
		const IndexBuffer& indexBufer,
		const IShader& shader
	) const;

};

#endif
