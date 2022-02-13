# JollyEngineTest
This project has been created to test the JollyEngine game development library.

# Build the project
Befor being able to build the project, we need to generate the makefiles with cmae,first. For this, create a directory named 'build' and switch into it by using following command:

`mkdir build && cd $_`

In the build diretory run following command to generate the makefile using cmake:

`cmake ..`

To finally build the project run following command in the build directory:

`make`

# Run the tests
After successfully building the project you only need to run following command form within the build directory to execute the tests:

`./JollyEngineTest`

# Prerequisites for development
## Initialize submodules
In addtion to the prerequisites of the JollyEngine project you will need to download the submodule googletest. You can do this by directly cloning the repository recursively using the following command:

`git clone --recurse-submodules https://github.com/J0llyver/JollyEngine.git`

If you have already cloned the repository without the --recurse-submodules flag you can run following commands to retrieve the submodule:

```
git submodule init
git pull --recurse-submodules
```

## Update submodules
To update the submodules run following command:

`git submodule update`

The submodules need to be initialized first.
