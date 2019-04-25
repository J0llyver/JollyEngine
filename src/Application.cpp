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
#include "Shader/Shader.h"

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

		Shader shader("resc/shaders/basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();



	    /* Loop until the user closes the window */
	    while (!glfwWindowShouldClose(window))
	    {
	        /* Render here */
	        glClear(GL_COLOR_BUFFER_BIT);

	        shader.Bind();
	        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

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