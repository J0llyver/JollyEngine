#include "Shader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Shader::Shader(const std::string& filepath) {
	this->filepath = filepath;
	this->rendererId = 0;

	ShaderProgramSource source = ParseShader();
	rendererId = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader(){}

void Shader::Bind() const {
	if (rendererId != 0){
		glUseProgram(rendererId);	
	}
	else {
		std::cout << "rendererId in Shader is 0!" << std::endl;
	}
}

void Shader::Unbind() const {
	glUseProgram(0);
}

unsigned int Shader::CompileShader(unsigned int type, const std::string & source){
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == 0){ // GL_FALSE == 0
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout 
			<< "Failed to compile " 
			<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
			<< std::endl;
		std::cout << message << std::endl;

		glDeleteShader(id);

		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
 
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

ShaderProgramSource Shader::ParseShader(){
	std::ifstream stream(filepath);

	enum class ShaderType{
		NONE =	 -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
 	ShaderType type = ShaderType::NONE;
	while(getline(stream, line)){
		if(line.find("#shader") != std::string::npos){
			if(line.find("vertex") != std::string::npos){
				type = ShaderType::VERTEX;
			}
			else if(line.find("fragment") != std::string::npos){
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << '\n'; 
		}
	}

	return {ss[0].str(), ss[1].str()};
}


void Shader::SetUniform1i(const std::string& name, int value){
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3){
	glUniform4f(
		GetUniformLocation(name), 
		v0, v1, v2, v3
	);
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix){
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

int Shader::GetUniformLocation(const std::string& name){
	int location;

	if(uniformLocationCache.find(name) != uniformLocationCache.end()){
		location = uniformLocationCache[name];
	}
	else {
		location = glGetUniformLocation(rendererId, name.c_str());
		if (location == -1) {
			std::cout << "Warning: uniform " << name << " does not exist" << std::endl;
		}
		uniformLocationCache[name] = location;
	}

	return location; 
}

