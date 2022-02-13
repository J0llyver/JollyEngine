# JollyEngine
Game Engine by J0llyver

# Prerequisites for development
## Dependencies
Note that the package names may vary depending on your linux distribution
Following packages need to be installed
* cmake - for building
* glew - Exposes OpenGL core and extension functionality in a single header file
* glfw-x11 - OpenGL library for creating windows

## Git configuration
The .githooks folder contains a pre-commit hook. For git to use it you have to run following command once in your repository:
``git config core.hooksPath ".githooks"``

# Build the project
Befor being able to build the project, we need to generate the makefiles with cmake, first. For this, create a directory named 'build' and switch into it by using following command:

``mkdir build && cd $_``

In the build diretory run following command to generate the makefile using cmake:

``cmake ..``

To finally build the project run following command in the build directory:

``make``
