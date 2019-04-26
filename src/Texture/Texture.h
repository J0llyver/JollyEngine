#include <string>

class Texture {
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }

private:
	unsigned int 	rendererId;
	std::string 	filePath;
	unsigned char* 	localBuffer;
	int 			width;
	int				height;
	int 			bpp;
};