/*
 * Helper.cpp
 *
 *  Created on: 07.04.2014
 *      Author: Helen
 */

#include "Helper.h"
#include "/opt/local/include/GLFW/glfw3.h"

void SetMaterialColor(int side, double r, double g, double b) {
    float	amb[4], dif[4], spe[4];
    int mat;

    dif[0] = r;
    dif[1] = g;
    dif[2] = b;

    for(int i = 0; i < 3; i++) {
        amb[i] = .1 * dif[i];
        spe[i] = .5;
    }
    amb[3] = dif[3] = spe[3] = 1.0;

    switch(side){
        case 1:	mat = GL_FRONT;
            break;
        case 2:	mat = GL_BACK;
            break;
        default: mat = GL_FRONT_AND_BACK;
    }

    glMaterialfv(mat, GL_AMBIENT, amb);
    glMaterialfv(mat, GL_DIFFUSE, dif);
    glMaterialfv(mat, GL_SPECULAR, spe);
    glMaterialf( mat, GL_SHININESS, 20);
}

