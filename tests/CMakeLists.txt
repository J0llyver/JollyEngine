cmake_minimum_required(VERSION 3.22)

project(JollyEngineTest)

enable_testing()
include(GoogleTest)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/googletest" "extern/googletest")

add_definitions(${CPP_VERSION_COMPILE_FLAG})
# Linked Libraries
# The compiler
set(CMAKE_C_COMPILER /usr/bin/g++)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CPP_VERSION_COMPILE_FLAG -std=c++20)

# Configure project source directory location
set(PROJECT_SOURCE_DIR src)

add_compile_options(-g -Wall -Wformat)
include_directories("extern/googletest/googletest/include")

set(PROJECT_TEST_CANDIDATE "../src")
set(PROJECT_TEST_CANDIDATE_VENDOR "../src/vendor")

# Cofigure path to the source of the project which needs to be tested
file(
  GLOB_RECURSE
  JOLLYENGINETEST_SRC
  "src/*.cpp"
  "src/*.h"
  "${PROJECT_TEST_CANDIDATE}/*.cpp"
  "${PROJECT_TEST_CANDIDATE}/*.h"
)

# Linked Libraries
set (LINK_LIBRARIES glfw X11 GL GLEW gtest)

add_executable(JollyEngineTest ${JOLLYENGINETEST_SRC})
target_include_directories(JollyEngineTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR} ${PROJECT_TEST_CANDIDATE} ${PROJECT_TEST_CANDIDATE_VENDOR})
target_link_libraries(JollyEngineTest ${LINK_LIBRARIES})
