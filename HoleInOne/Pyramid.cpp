//
//  Pyramid.cpp
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#include "Pyramid.h"

Pyramid::Pyramid(Vec3 vec) {
    this->status = MOVERIGHT;
    this->v = vec;
}

void Pyramid::draw() {

    if(this->getPickStatus() == PICKED_YES) {
            SetMaterialColor(0, 5, 5, 5);
    } else {
        SetMaterialColor(0, 0, 4, 12);
    }
    
    glPushMatrix();
    glTranslated(v.p[0], v.p[1], v.p[2]);
    
    //    glNormal3f(0.0, 0.0, pos);
    // viereck
    glBegin(GL_QUADS);
    
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    glEnd();
    
    glBegin(GL_TRIANGLES);
    
    // front
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    
    // right
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    // back
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    // left
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glEnd();
    
    glPopMatrix();
}