#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS


struct ImGuiContext* ctx;
struct ImGuiIO* io;
   
GLFWwindow* createWindow(GLuint WIDTH, GLuint HEIGHT){// Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "gfx", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        printf("Error creating window");
        glfwTerminate();
        return NULL;
    }
   
    return window;
    }