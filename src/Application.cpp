#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer/Renderer.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "VertexArray/VertexArray.h"

struct ShaderProgramSource{
	std::string VertexSource;
	std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string& filepath){
	std::ifstream stream(filepath);

	enum class ShaderType{
		NONE = -1,
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

static unsigned int CompileShader( unsigned int type, const std::string & source){
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

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
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

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Canvas", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
    	std::cout << "Failed to initialize glew!" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;
    {
	    float positions[8] = {
	    	-0.5f, -0.5f,
	    	 0.5f, -0.5f,
	    	 0.5f,  0.5f,
	    	-0.5f,  0.5f
	    }; 

	    unsigned int indices[6] = {
	    	0, 1, 2,
	    	2, 3, 0
	    };

	    VertexArray va;
	    VertexBuffer vb(positions, 4 * 2 * sizeof(float));

	    VertexBufferLayout layout;
	    layout.Push(GL_FLOAT, 2);
	    va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		ShaderProgramSource source = ParseShader("resc/shaders/basic.shader");

		unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
		glUseProgram(shader);

		int location = glGetUniformLocation(shader, "u_Color");

	    /* Loop until the user closes the window */
	    while (!glfwWindowShouldClose(window))
	    {
	        /* Render here */
	        glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shader);
			glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f);

			va.Bind();
			ib.Bind();

	        // Create class Painter that takes objects to draw and a canvas to draw on
	        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	        /* Swap front and back buffers */
	        glfwSwapBuffers(window);

	        /* Poll for and process events */
	        glfwPollEvents();
	    }

	    // glDeleteProgram(shader);
	}
    glfwTerminate();
    return 0;
}