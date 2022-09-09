#include <stdlib.h>
#include <glad/glad.h>
#include "../../libs/cshader.h"

Shader shader;
GLuint vao;


void genPrimitive(){

    shader = ShaderInit();
    float points[] = {
    -1.0f,  1.0f,  0.0f,
    1.0f,   1.0f,  0.0f,
    -1.0f, -1.0f,  0.0f,
    1.0f,  -1.0f,  0.0f

    };

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), points, GL_STATIC_DRAW);

    vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    shader.Load(&shader,"src/shaders/mandlebrot.vert","src/shaders/mandlebrot.frag");
    //GLuint c = glGetUniformLocation(shader.program,"col");



}
void drawMandleBrot(){
    glUseProgram(shader.program);
    glBindVertexArray(vao);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
