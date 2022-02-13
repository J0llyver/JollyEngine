cmake_minimum_required(VERSION 3.22)

project (JollyEnginePlayground)

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

set(JOLLY_ENGINE_SRC "../../src")
set(JOLLY_ENGINE_EXTERN "../../extern")

file(
  GLOB_RECURSE
  JOLLYENGINEPLAYGROUND_SRC
  "src/*.cpp"
  "src/*.h"
  "${JOLLY_ENGINE_SRC}/*.cpp"
  "${JOLLY_ENGINE_SRC}/*.h"
  "${JOLLY_ENGINE_EXTERN}/*.cpp"
  "${JOLLY_ENGINE_EXTERN}/*.h"
)

add_executable(JollyEnginePlayground ${JOLLYENGINEPLAYGROUND_SRC})
target_include_directories(JollyEnginePlayground PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR} ${JOLLY_ENGINE_SRC} ${JOLLY_ENGINE_EXTERN})
target_link_libraries(JollyEnginePlayground ${LINK_LIBRARIES})

# Copy local resources to the binary folder
set(PLAYGROUND_RESOURCES "resc")
file(COPY ${PLAYGROUND_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR})

# Copy JollyEngine resources to binary folder
set(JOLLY_ENGINE_RESOURCES "../../resc")
file(COPY ${JOLLY_ENGINE_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR})
