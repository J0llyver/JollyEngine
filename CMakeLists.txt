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

file(
  GLOB_RECURSE
  JOLLYENGINE_SRC
  "src/*.cpp"
  "src/*.h"
)

add_executable(JollyEngine ${JOLLYENGINE_SRC})
target_link_libraries(JollyEngine ${LINK_LIBRARIES})
