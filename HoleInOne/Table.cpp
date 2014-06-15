//
//  Table.cpp
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#include "Table.h"

Table::Table() {
    
}

void Table::draw() {
    glShadeModel(GL_FLAT);
    
    // unten
    SetMaterialColor(1, 12, 0, 0);
    SetMaterialColor(2, 0, 0, 12);
    glBegin(GL_QUADS);
    glNormal3f(0, 1.0, 0.0);
    glVertex3f(-7.0f, -1.0f, 5.0f);
    glVertex3f(7.0f, -1.0f, 5.0f);
    glVertex3f(7.0f, -1.0f, -5.0f);
    glVertex3f(-7.0f, -1.0f, -5.0f);
    glEnd();
    
    // links
    SetMaterialColor(2, 12, 0, 0);
    SetMaterialColor(1, 0, 0, 12);
    glBegin(GL_QUADS);
    glNormal3f(1, 0, 0);
    glVertex3f(-7.0f, -1.0f, -5.0f);
    glVertex3f(-7.0f, -1.0f, 5.0f);
    glVertex3f(-7.0f, 0.0f, 5.0f);
    glVertex3f(-7.0f, 0.0f, -5.0f);
    glEnd();
    
    // rechts
    SetMaterialColor(2, 12, 0, 0);
    SetMaterialColor(1, 0, 0, 12);
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0, 0);
    glVertex3f(7.0f, 0.0f, -5.0f);
    glVertex3f(7.0f, 0.0f, 5.0f);
    glVertex3f(7.0f, -1.0f, 5.0f);
    glVertex3f(7.0f, -1.0f, -5.0f);
    glEnd();
    
    // vorne
    SetMaterialColor(2, 12, 0, 0);
    SetMaterialColor(1, 0, 0, 12);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1.0);
    glVertex3f(-7.0f, -1.0f, 5.0f);
    glVertex3f(7.0f, -1.0f, 5.0f);
    glVertex3f(7.0f, 0.0f, 5.0f);
    glVertex3f(-7.0f, 0.0f, 5.0f);
    glEnd();
    
    // hinten
    SetMaterialColor(1, 12, 0, 0);
    SetMaterialColor(2, 0, 0, 12);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1.0);
    glVertex3f(7.0f, 0.0f, -5.0f);
    glVertex3f(-7.0f, 0.0f,0 -5.0f);
    glVertex3f(-7.0f, -1.0f, -5.0f);
    glVertex3f(7.0f, -1.0f, -5.0f);
    glEnd();
}
