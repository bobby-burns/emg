#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

// Callback Prototypes
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void window_size_callback(GLFWwindow* window, int width, int height);

// Mouse coordinates in screen spact
int mouseX,mouseY;

GLFWwindow* window;

// Viewport width and height
int v_width;
int v_height;
   
GLFWwindow* createWindow(GLuint WIDTH, GLuint HEIGHT) {
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // This is for Apple devices
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "EMG", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        printf("Error creating window");
        glfwTerminate();
        return NULL;
    }

    // Set callback functions
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);

   
    return window;
    }

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    mouseX = xpos;
    mouseY = ypos;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

// Viewport updater function
void getViewport(){
    glfwGetFramebufferSize(window,&v_width,&v_height);
}
// Update viewport whenver the window is resized
void window_size_callback(GLFWwindow* window, int width, int height) {
    getViewport();
}