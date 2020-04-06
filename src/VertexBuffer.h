#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#pragma once

class VertexBuffer{
private:
	unsigned int rendererID;

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};

#endif
