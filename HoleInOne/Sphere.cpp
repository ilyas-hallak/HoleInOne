//
//  Sphere.cpp
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#include "Sphere.h"

// draw a sphere composed of triangles
void Sphere::DrawSphere(const Vec3& ctr, double r) {
    int     i, j,
    n1 = 20, n2 = 80;
    Vec3    normal, v1;
    double  a1, a1d = M_PI / n1,
    a2, a2d = M_PI / n2,
    s1, s2,
    c1, c2;
    
    glShadeModel(GL_SMOOTH);
    for(i = 0; i < n1; i++){
        a1 = i * a1d;
        
        glBegin(GL_TRIANGLE_STRIP);
        for(j = 0; j <= n2; j++){
            a2 = (j + .5 * (i % 2)) * 2 * a2d;
            
            s1 = sin(a1);
            c1 = cos(a1);
            s2 = sin(a2);
            c2 = cos(a2);
            normal = c1 * XVec3 + s1 * (c2 * YVec3 + s2 * ZVec3);
            v1 = ctr + r * normal;
            glNormal3dv(normal.p);
            glVertex3dv(v1.p);
            
            s1 = sin(a1 + a1d);
            c1 = cos(a1 + a1d);
            s2 = sin(a2 + a2d);
            c2 = cos(a2 + a2d);
            normal = c1 * XVec3 + s1 * (c2 * YVec3 + s2 * ZVec3);
            v1 = ctr + r * normal;
            glNormal3dv(normal.p);
            glVertex3dv(v1.p);
        }
        glEnd();
    }
}

Sphere::Sphere(Vec3 vec,double r) {
    this->v = vec;
    this->radius = r;
}


void Sphere::draw() {
    glPushMatrix();
    if(this->getPickStatus() == PICKED_YES) {
        SetMaterialColor(0, 5, 5, 5);
    } else {
        SetMaterialColor(0, 1, 2, 3);
    }
    this->DrawSphere(v, radius);
    glPopMatrix();
}

