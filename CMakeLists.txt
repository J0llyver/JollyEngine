cmake_minimum_required (VERSION 3.10)

project (JollyEngine)

# Linked Libraries
set (LINK_LIBRARIES glfw X11 GL GLEW)

# The compiler
set (CMAKE_C_COMPILER /usr/bin/g++)
set (CMAKE_CXX_COMPILER /usr/bin/g++)
set (CPP_VERSION_COMPILE_FLAG -std=c++1z)
add_definitions(${CPP_VERSION_COMPILE_FLAG})

# Configure project source directory location
set (PROJECT_SOURCE_DIR src)

# Configure build output location
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options(-g -Wall -Wformat)

include_directories("${PROJECT_BINARY_DIR}" "src/vendor")

add_executable(
	JollyEngine

	src/Application.cpp

	src/Object.h
	src/Object.cpp

	src/VertexBuffer.h
	src/VertexBuffer.cpp

	src/IndexBuffer.h
	src/IndexBuffer.cpp

	src/VertexArray.h
	src/VertexArray.cpp

	src/VertexBufferLayout.h	
	src/VertexBufferLayout.cpp	

	src/Shader.h
	src/Shader.cpp

	src/OpenGLRenderer.h
	src/OpenGLRenderer.cpp

	src/Texture.h
	src/Texture.cpp

	src/Mesh/MeshPrimitiveType.h
	src/Mesh/Mesh.h
	src/Mesh/Mesh.cpp
	src/Mesh/MeshPrimitiveFactory.h
	src/Mesh/MeshPrimitiveFactory.cpp
	src/Mesh/MeshStore.h
	src/Mesh/MeshStore.cpp

	src/vendor/stb_image/stb_image.h
	src/vendor/stb_image/stb_image.cpp

	src/vendor/imgui/imgui.cpp
	src/vendor/imgui/imgui.h
	src/vendor/imgui/imgui_demo.cpp
	src/vendor/imgui/imgui_draw.cpp
	src/vendor/imgui/imgui_widgets.cpp
	src/vendor/imgui/imgui_internal.h
	src/vendor/imgui/imconfig.h

	src/vendor/imgui/imstb_rectpack.h
	src/vendor/imgui/imstb_textedit.h
	src/vendor/imgui/imstb_truetype.h

	src/vendor/imgui/imgui_impl_opengl3.cpp
	src/vendor/imgui/imgui_impl_opengl3.h
	src/vendor/imgui/imgui_impl_glfw.h
	src/vendor/imgui/imgui_impl_glfw.cpp
)

target_link_libraries(JollyEngine ${LINK_LIBRARIES} )
