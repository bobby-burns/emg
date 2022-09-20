#include <stdlib.h>
#include <glad/glad.h>
#include "../../libs/cshader.h"
#include "../win.h"



void genLorenz(double* x, double* y, double* z, double a, double b, double c, double t){
        double xt = *x + t * a * (*y - *x);

        double yt = *y + t * (*x * (b - *z) - *y);

        double zt = *z + t * (*x * *y - c * *z);

        *x = xt;

        *y = yt;

        *z = zt;

    
}