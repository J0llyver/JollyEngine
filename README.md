# JollyEngine
Game Engine by J0llyver

# Prerequisites for development
## Dependencies
Note that the package names may vary depending on your linux distribution
Following packages need to be installed
* cmake - for building
* ctags - for code navigation
* glew - Exposes OpenGL core and extension funcitonality in a single head file
* glfw-x11 - OpenGL library for creating windows

## Git configuration
The .githooks folder contains a pre-commit hook. For git to use it you have to run following command once in your repository:
`git config core.hooksPath ".githooks"

# To build the project run following command
`./build.sh` - This command only needs to run once and after changing the CMakeLists.txt
`make`



