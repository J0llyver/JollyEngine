#include <GL/glew.h>

#include "../IndexBuffer/IndexBuffer.h"
#include "../VertexArray/VertexArray.h"
#include "../Shader/Shader.h"

class Renderer{
public:
	
	void Clear() const;

	void Draw(
		const VertexArray& vertexArray,
		const IndexBuffer& indexBufer,
		const Shader& shader
	) const;

};

