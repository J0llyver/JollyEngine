cmake_minimum_required (VERSION 3.10)
project (JollyEngine)

# Linked Libraries
set (LINK_LIBRARIES glfw X11 GL GLEW)

# The compiler
set (CMAKE_C_COMPILER /usr/bin/g++)
set (CMAKE_CXX_COMPILER /usr/bin/g++)

add_compile_options(-g -Wall)

include_directories("${PROJECT_BINARY_DIR}")
add_executable(
	JollyEngine 

	src/Application.cpp

	src/VertexBuffer/VertexBuffer.h
	src/VertexBuffer/VertexBuffer.cpp

	src/IndexBuffer/IndexBuffer.h
	src/IndexBuffer/IndexBuffer.cpp

	src/VertexArray/VertexArray.h
	src/VertexArray/VertexArray.cpp

	src/VertexBufferLayout/VertexBufferLayout.h	
	src/VertexBufferLayout/VertexBufferLayout.cpp	

	src/Shader/Shader.h
	src/Shader/Shader.cpp

	src/Renderer/Renderer.h
	src/Renderer/Renderer.cpp

	src/Texture/Texture.h
	src/Texture/Texture.cpp

	src/vendor/stb_image/stb_image.h
	src/vendor/stb_image/stb_image.cpp


)

target_link_libraries(JollyEngine ${LINK_LIBRARIES} )