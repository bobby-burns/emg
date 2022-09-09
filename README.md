# EMG

EMG stands for __Exploration of Math Graphically__

It is a hobby project meant for me to learn C and computer graphics, while also having some fun with interesting mathmatical models.

## Structure

The project is setup as *modules*, and more modules are meant to be added on. Currently, only the __Mandlebrot__ module exists. This is a visualization of the mandlebrot fractal entirely in a fragment shader for efficiency.


## Building
This project relies on the following libraries:
* OpenGL 4.1
* GLFW3

Compile all .c files and link with opengl and glfw (an example makefile is included, this one is meant for Mac with a silicon chip)