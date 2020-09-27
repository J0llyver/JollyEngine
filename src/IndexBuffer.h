#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include <vector>

class IndexBuffer{
private:
	unsigned int rendererID;
	unsigned int count;

public:
	IndexBuffer(const std::vector<unsigned int>* indexBuffer, unsigned int count);
	IndexBuffer(const unsigned int* indexBuffer, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return count; }
};

#endif
