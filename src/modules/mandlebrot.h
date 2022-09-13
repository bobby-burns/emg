#ifndef MANDLEBROT_H_   
#define MANDLEBROT_H_
#include "../../libs/cshader.h"

extern Shader shader;
void genPrimitive();

void drawMandleBrot();
void setUniforms(int vx, int vy, double minX, double maxX, double minY, double maxY, float zoomFactor);

#endif 