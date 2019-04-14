cmake_minimum_required (VERSION 3.10)
project (JollyEngine)

# The version number
set (JollyEngine_VERSION_MAJOR 0)
set (JOllyEngine_VERSION_MINOR 1)
set (LINK_LIBRARIES glfw X11 GL GLEW)

# The compiler
set (CMAKE_C_COMPILER /usr/bin/g++)
set (CMAKE_CXX_COMPILER /usr/bin/g++)

configure_file(
	"${PROJECT_SOURCE_DIR}/ApplicationConfig.h.in"
	"${PROJECT_BINARY_DIR}/ApplicationConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")
add_executable(
	JollyEngine 
	Application.cpp
	VertexBuffer/VertexBuffer.h
	VertexBuffer/VertexBuffer.cpp
	IndexBuffer/IndexBuffer.h
	IndexBuffer/IndexBuffer.cpp
	VertexArray/VertexArray.h
	VertexArray/VertexArray.cpp
	VertexBufferLayout/VertexBufferLayout.h	
	VertexBufferLayout/VertexBufferLayout.cpp	

)

target_link_libraries(JollyEngine ${LINK_LIBRARIES} )