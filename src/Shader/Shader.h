#include <string>
#include <unordered_map>

struct ShaderProgramSource{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
private:
	unsigned int rendererId;
	std::string filepath;
	std::unordered_map<std::string, unsigned int> uniformLocationCache;

	unsigned int CompileShader(unsigned int type, const std::string & source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgramSource ParseShader();

	unsigned int GetUniformLocation(const std::string& name);


public:
	Shader(const  std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
};