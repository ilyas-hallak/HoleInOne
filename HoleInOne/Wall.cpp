//
//  Wall.cpp
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#include "Wall.h"

Wall::Wall() {
    
}

void Wall::draw() {
    // links

    SetMaterialColor(2, 12, 0, 0);
    SetMaterialColor(1, 0, 0, 12);
    glBegin(GL_QUADS);
//    glNormal3f(5, 5, 5);
    glVertex3f(-4.0f, -1.0f, -2.0f);
    glVertex3f(-4.0f, -1.0f, 2.0f);
    glVertex3f(-4.0f, 0.0f, 2.0f);
    glVertex3f(-4.0f, 0.0f, -2.0f);
    glEnd();
}