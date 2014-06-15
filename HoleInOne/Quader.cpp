//
//  Quader.cpp
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#include "Quader.h"
#include <stdio.h>

Quader::Quader(Vec3 vec) {
    this->v = vec;
}

void Quader::draw() {
    
    
    glTranslated(v.p[0], v.p[1], v.p[2]);
    std::cout << "pickedstatus q " << this->getPickStatus() << std::endl;
    
    if(this->getPickStatus() == PICKED_YES) {
        SetMaterialColor(0, 5, 5, 5);
    }
    
    // unten
    if(this->getPickStatus() == PICKED_NO) {
        SetMaterialColor(1, 12, 0, 0);
        SetMaterialColor(2, 0, 0, 12);
    }
    
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glEnd();
    
    // oben
    if(this->getPickStatus() == PICKED_NO) {
        SetMaterialColor(2, 12, 0, 0);
        SetMaterialColor(1, 0, 0, 12);
    }
    glBegin(GL_QUADS);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glEnd();
    
    glPopMatrix();
  
    // links
    if(this->getPickStatus() == PICKED_NO) {
        SetMaterialColor(2, 12, 0, 0);
        SetMaterialColor(1, 0, 0, 12);
    }
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    
    // rechts
    if(this->getPickStatus() == PICKED_NO) {
        SetMaterialColor(1, 12, 0, 0);
        SetMaterialColor(2, 0, 0, 12);
    }
    glBegin(GL_QUADS);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();
    
    // vorne
    if(this->getPickStatus() == PICKED_NO) {
        SetMaterialColor(2, 12, 0, 0);
        SetMaterialColor(1, 0, 0, 12);
    }
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
    
    
    // hinten
    if(this->getPickStatus() == PICKED_NO) {
        SetMaterialColor(1, 12, 0, 0);
        SetMaterialColor(2, 0, 0, 12);
    }
    glBegin(GL_QUADS);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
    
}
