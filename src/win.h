#ifndef WIN_H_   
#define WIN_H_
#include <GLFW/glfw3.h>

extern int mouseX,mouseY;
extern int v_width,v_height;

GLFWwindow* createWindow(int WIDTH, int HEIGHT);
void getViewport(); 

#endif 