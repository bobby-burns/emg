#include <stdlib.h>
#include <glad/glad.h>
#include "../../libs/cshader.h"
#include "../win.h"

Shader shader;
GLuint vao;
GLint vloc, mcoords, zoomFactor;

// Center X and Y coordinates of the mandlebrot space. Change these to move around.
long double X  = -0.745428;
long double Y  = 0.113009;
// Size of the mandlebrot image, smaller number is more zoom.
long double size = 2e-5;



void genPrimitive(){

    // Init shader loading library
    shader = ShaderInit();

    // A rectangle covering the entire screen.
    float points[] = {
    -1.0f,  1.0f,  0.0f,
    1.0f,   1.0f,  0.0f,
    -1.0f, -1.0f,  0.0f,
    1.0f,  -1.0f,  0.0f

    };

    // Vertex Buffer Oject creation and memory allocation
    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), points, GL_STATIC_DRAW);

    // Vertex Array Object creation, binding, and setting memory.
    vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // Load the respective shaders.
    shader.Load(&shader,"src/shaders/mandlebrot.vert","src/shaders/mandlebrot.frag");

    // Retrieve uniforms from the shaders. These uniforms are found in the fragment shader.
    vloc = glGetUniformLocation(shader.program,"viewport");
    mcoords = glGetUniformLocation(shader.program,"mandle_coords");
    zoomFactor = glGetUniformLocation(shader.program,"zoomFactor");


}

// Setting the shader uniforms.
void setUniforms(int vx, int vy, double minX, double maxX, double minY, double maxY, float zoomF) {
    glProgramUniform2f(shader.program,vloc,vx,vy);
    glProgramUniform4f(shader.program,mcoords,minX,maxX,minY,maxY);
    glProgramUniform1f(shader.program,zoomFactor,zoomF);
}

void drawMandleBrot() {
    // Calculate mandlebrot image space
    long double minX = X - size,maxX = X + size, minY = Y - size, maxY = Y +size;

    // Set uniforms before drawing.
    setUniforms(v_width,v_height,minX,maxX,minY,maxY,1);

    // Use the shaders, bind the vao, and draw the quad.
    glUseProgram(shader.program);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

