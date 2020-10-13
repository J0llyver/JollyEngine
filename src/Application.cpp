#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "IndexBuffer.h"
#include "Mesh/MeshPrimitiveType.h"
#include "Mesh/MeshPrimitiveFactory.h"
#include "OpenGLRenderer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexBuffer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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
	window = glfwCreateWindow(960, 540, "Canvas", NULL, NULL);
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
		auto meshPrimitiveFactory = new MeshPrimitiveFactory();

		const Mesh* squareMesh;
		meshPrimitiveFactory->LoadPrimitive(MeshPrimitiveType::Square, squareMesh);

		const std::vector<float> positions = squareMesh->GetVertexBuffer();
		VertexBuffer vb(&positions[0], positions.size() * sizeof(float));

		VertexArray va;
		VertexBufferLayout layout;
		layout.Push(GL_FLOAT, 2);
		layout.Push(GL_FLOAT, 2);
		va.AddBuffer(vb, layout);

		const std::vector<unsigned int> indices = squareMesh->GetIndexBuffer();
		IndexBuffer ib(&indices[0], indices.size());

		glm::vec3 objectPosition(100,100,0);
		glm::mat4 projectionMatrix = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,0));
		glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), objectPosition);

		glm::mat4 modelViewProjectionMatrix = projectionMatrix * viewMatrix * modelMatrix;

		Texture texture("resc/textures/DwarfFortressMap.png");
		texture.Bind();

		va.Unbind();
		vb.Unbind();
		ib.Unbind();	

		OpenGLRenderer renderer;
		
		const char* glsl_version = "#version 130";
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);

		ImGui::StyleColorsDark();

		// Our state
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();

			modelMatrix = glm::translate(glm::mat4(1.0f), objectPosition);
			modelViewProjectionMatrix = projectionMatrix * viewMatrix * modelMatrix;

			// Move to globally accessable shader
			Shader shader("resc/shaders/basic.shader");

			shader.Bind();
			shader.SetUniformMat4f("u_MVP", modelViewProjectionMatrix);
			shader.SetUniform1i("u_Texture", 0);
			shader.Unbind();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			{
				ImGui::Begin("Hello, world!");

				ImGui::SliderFloat("Position X", &objectPosition.x, 0.0f, 960.0f);
				ImGui::SliderFloat("Position Y", &objectPosition.y, 0.0f, 540.0f);
				ImGui::ColorEdit3("clear color", (float*)&clear_color);

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
				ImGui::End();
			}

			renderer.Draw(va, ib, shader);

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		delete meshPrimitiveFactory;

		// Cleanup
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	glfwTerminate();
	return 0;
}
