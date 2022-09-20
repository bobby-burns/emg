#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <assert.h>
#include "win.h"
#include "modules/mandlebrot.h"
#include "modules/lorenz.h"
#include "utils.h"




// Window dimensions
const GLuint WIDTH = 1280, HEIGHT = 720;

enum modules cur;

// The MAIN function, from here we start the application and run the main loop
int main()
{   
    // GLFW Window
    GLFWwindow* window = createWindow(WIDTH,HEIGHT);
    assert(window != NULL);
    cur = MODULE_MANDLEBROT;  

   
    // Init glad and opengl, make sure we load and link correctly
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        return -1;
    }
    printf("Loaded Version: %s \n",glGetString(GL_VERSION));

   
    // Generate the primitve for the mandlebrot, which is a rectangle covering the screen.
    if(cur==MODULE_MANDLEBROT){
        genPrimitive();
    }

    // First time viewport set
    getViewport();
    glViewport(0,0,v_width,v_height);
    double x = 0.1;
    double y = 0, z = 0;

    for (float i = 0.01; i < 1; i += 0.01){
        genLorenz(&x,&y,&z,10.0,28.0,8.0/3.0,i);
        printf("X: %f, Y: %f, Z: %f \n",x,y,z);
    }
   
    
    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Update viewport
        getViewport();
        glViewport(0,0,v_width,v_height);


        if (cur==MODULE_MANDLEBROT){
            drawMandleBrot();
        }


        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    destroyWindow();
    return 0;
}

