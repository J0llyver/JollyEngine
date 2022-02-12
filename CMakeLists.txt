cmake_minimum_required(VERSION 3.22)

project (JollyEngine)

# Linked Libraries
set (LINK_LIBRARIES glfw X11 GL GLEW)

# The compiler
set (CMAKE_C_COMPILER /usr/bin/g++)
set (CMAKE_CXX_COMPILER /usr/bin/g++)
set (CPP_VERSION_COMPILE_FLAG -std=c++20)
add_definitions(${CPP_VERSION_COMPILE_FLAG})

# Configure project source directory location
set (PROJECT_SOURCE_DIR src)

add_compile_options(-g -Wall -Wformat)

include_directories("${PROJECT_BINARY_DIR}" "src/vendor")

file(
  GLOB_RECURSE
  JOLLYENGINE_SRC
  "src/*.cpp"
  "src/*.h"
)

add_executable(JollyEngine ${JOLLYENGINE_SRC})
target_include_directories(JollyEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR})
target_link_libraries(JollyEngine ${LINK_LIBRARIES})

# Copy resources to the binary folder
file(COPY "resc" DESTINATION ${CMAKE_BINARY_DIR})


