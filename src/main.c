#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <assert.h>
#include "win.h"
#include "modules/mandlebrot.h"
#include "utils.h"


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 1280, HEIGHT = 720;

enum modules cur;

// The MAIN function, from here we start the application and run the main loop
int main()
{
    GLFWwindow* window = createWindow(WIDTH,HEIGHT);
    assert(window != NULL);
    cur = MODULE_MANDLEBROT;  

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        return -1;
    }
    printf("Loaded Version: %s \n",glGetString(GL_VERSION));

   

    if(cur==MODULE_MANDLEBROT){
        genPrimitive();
    }
    // set uniforms
    GLint vloc = glGetUniformLocation(shader.program,"viewport");
    
    

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

         // Define the viewport dimensions
         // TODO: Extract this
        int calc_width,calc_height;
        glfwGetFramebufferSize(window,&calc_width,&calc_height);
        glViewport(0, 0, calc_width, calc_height);
        glProgramUniform2f(shader.program,vloc,calc_width,calc_height);
        
        if(cur==MODULE_MANDLEBROT){
            drawMandleBrot();
        }

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Terminates GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}