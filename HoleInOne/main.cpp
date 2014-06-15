//
//  main.cpp
//  HoleInOne
//
//  Created by Ilyas Hallak on 13.05.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#include <iostream>
#include "/opt/local/include/GLFW/glfw3.h"

#define GLFW_DLL
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>
#include "vec3.hpp"
#include "Table.h"
#include "Helper.h"
#include "Pyramid.h"
#include "Quader.h"
#include "Sphere.h"
#include "Wall.h"

#include <vector>

#define SPHERE_MOVING 3
#define SPHERE_STOPPED 4

int window_width_ = 1024, window_height_ = 768;

using namespace std;

vector<Obj *>obstacles;

static double alpha_ = 90, beta_ = 20;
double moveX = 0, moveY = 0, moveZ;
double mouseX = 0, mouseY = 0, mousePressedX = 0, mousePressedY = 0;

static double sphX = 5.0, sphZ = 0.0, cubeX = 0, cubeY = 0;

Vec3 currSph = Vec3(0.0, 0.0, 0.0);

int sphereStatus = SPHERE_STOPPED;

int selectedIndex = -1;

void move(GLFWwindow *w, int key, int scancode, int action, int mods) {
    if(action == 0) return;
    
    // select obstacle
    if(key >= GLFW_KEY_0 && key <= GLFW_KEY_9) {
        int index = key - 48;
        cout << "key :" << index << endl;
        selectedIndex = index;
        
        // reset all obstacles
        for(std::vector<int>::size_type i = 0; i != obstacles.size(); i++) {
            obstacles[i]->pick(PICKED_NO);
        }
        
        // set new obstacle to picked
        if(obstacles.size() >= index) {
            obstacles[index]->pick(PICKED_YES);
        }
    }
    
    cout << "selectedIndex " << selectedIndex << endl;
    
    if(selectedIndex != -1) {
        // set new obstacle to picked
        if(obstacles.size() >= selectedIndex) {
            obstacles[selectedIndex]->pick(PICKED_YES);
            obstacles[selectedIndex]->move(key);
        }
    }
    
    switch(key) {
        case GLFW_KEY_LEFT:
            alpha_ -= 20;
            break;
        case GLFW_KEY_UP:
            beta_ -= 20;
            break;
        case GLFW_KEY_RIGHT:
            alpha_ += 20;
            break;
        case GLFW_KEY_DOWN:
            beta_ += 20;
            break;
        case GLFW_KEY_A:
            moveX -= 1;
            break;
        case GLFW_KEY_D:
            moveX += 1;
            break;
        case GLFW_KEY_W:
            moveY += 1;
            break;
        case GLFW_KEY_S:
            moveY -= 1;
            break;
        case GLFW_KEY_O:
            moveZ -= 1;
            break;
        case GLFW_KEY_I:
            moveZ += 1;
            break;
        default: break;
    }
}

void mouseMove(GLFWwindow *w, double x, double y) {
    // cout << endl << "X " << x << " Y " << y;
    mouseX = x;
    mouseY = y;
}

void mouseButtonC(GLFWwindow *w, int button, int action, int mods) {
    if(action == GLFW_PRESS) {
        mousePressedX = mouseX;
        mousePressedY = mouseY;
    } else if (action == GLFW_RELEASE) {
        sphereStatus = SPHERE_MOVING;
        currSph = Vec3(-(mousePressedX - mouseX) / 200 ,0.0, -(mousePressedY - mouseY) / 200);
    }
}

void InitLighting() {
    GLfloat lp1[4]  = { 10,  5,  10,  0};
    GLfloat lp2[4]  = { -5,  5, -10,  0};
    GLfloat red[4]  = {1.0, .8,  .8,  1};
    GLfloat blue[4] = { .8, .8, 1.0,  1};
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glShadeModel(GL_SMOOTH);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
    glEnable(GL_LIGHTING);
    
    glLightfv(GL_LIGHT1, GL_POSITION, lp1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  red);
    glLightfv(GL_LIGHT1, GL_SPECULAR, red);
    glEnable(GL_LIGHT1);
    
    glLightfv(GL_LIGHT2, GL_POSITION, lp2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  blue);
    glLightfv(GL_LIGHT2, GL_SPECULAR, blue);
    glEnable(GL_LIGHT2);
    
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // init viewport to canvassize
    glViewport(0, 0, window_width_, window_height_);
    
    // init coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-15, 15, -10, 10, -20, 20);
    glFrustum(-2, 2, -3, 3, 2, 25);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// draw a sphere composed of triangles
void DrawSphere(const Vec3& ctr, double r){
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

void Draw() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();               // Reset The Current Modelview Matrix
    glTranslated(0, -2, -12);      // Move 10 units backwards in z,
    
    // since camera is at origin
    glRotated(alpha_, 0, 3, 1);
    //  alpha_ += .1;
    
    glRotated(beta_, 1, 0, 0);
    //  beta_ += .1;
    
    
	// Vec3 *clickPoint = new Vec3(window_x, 0.0, window_y);
    
	// currSph = Vec3( 5.0, 0.0, 0.0);
    float radiusSpH = 0.2f;
    
    int window_y = (mouseY - window_height_/2 - sphZ) * 1;
	int window_x = (mouseX - window_width_/2 - sphX) * 1;
    
	// cout << "X " << window_x  << " Y" << window_y << endl;
    
    /*
	double x2 = clickPoint->p[0];
	double x1 = sph->p[0];
    
	double y2 = clickPoint->p[2];
	double y1 = sph->p[2];
    
	double abstand = sqrt(pow(x1 - x2, 2)  + pow(y1 - y2, 2));
    
	cout << "abstand " << abstand << endl;
    
    
    if (sphX + radiusSpH < cubeX+6) {
        Vec3 normalVektor = Vec3(1, 0 ,0);
        currSph = -(2 * (currSph * normalVektor) * normalVektor - currSph);
        cout << "1" << endl;
        // links
    } else if (sphX - radiusSpH < cubeX-7) {
        Vec3 normalVektor = Vec3(-1, 0 ,0);
        currSph = -(2 * (currSph * normalVektor) * normalVektor - currSph);
        
        // oben
        cout << "2" << endl;
    }
    
    if (sphZ + radiusSpH > cubeY+5) {
        Vec3 normalVektor = Vec3(0, 0 ,1);
        currSph = -(2 * (currSph * normalVektor) * normalVektor - currSph);
        cout << "3" << endl;
        // unten
    } else if (sphZ - radiusSpH < cubeY-5) {
        Vec3 normalVektor = Vec3(0, 0 ,-1);
        currSph = -(2 * (currSph * normalVektor) * normalVektor - currSph);
                cout << "4" << endl;
    }
    
    cout << "curr x: " << currSph.p[0] << " y: " << currSph.p[2] << endl;
    
    SetMaterialColor(0, 12, 7, 1);

    DrawSphere(currSph, radiusSpH);
    */
    
    // hindernisse
    SetMaterialColor(0, 15, 0, 1);
    
    for(std::vector<int>::size_type i = 0; i != obstacles.size(); i++) {
        obstacles[i]->draw();
    }
    
}

int main(int argc, const char * argv[])
{
    
    GLFWwindow* window = NULL;
    
    
    printf("Here we go!\nPlease use arrow keys to move the objects.");
    
    if(!glfwInit()){
        return -1;
    }
    
    window = glfwCreateWindow(window_width_, window_height_,
                              "Simple 3D Animation", NULL, NULL);

    if(!window) {
        glfwTerminate();
        return -1;
    }
    
    // create
    obstacles.push_back(new Table());
    obstacles.push_back(new Pyramid(Vec3(1.0, 0.0, 1.0)));
    obstacles.push_back(new Pyramid(Vec3(3.0, 0.0, 2.0)));
    //obstacles.push_back(new Quader(Vec3(-2.0, 0.0, -3.0)));
    obstacles.push_back(new Sphere(Vec3(3.0, 0.0, 3.0), 0.5));
    obstacles.push_back(new Wall());
    
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, &move);
    glfwSetCursorPosCallback(window, &mouseMove);
    
    glfwSetMouseButtonCallback(window, &mouseButtonC);
    
    
    while(!glfwWindowShouldClose(window)) {
        // switch on lighting (or you don't see anything)
        InitLighting();
        
        // set background color
        glClearColor(0.8, 0.8, 0.8, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // draw the scene
        Draw();
        
        // make it appear (before this, it's hidden in the rear buffer)
        glfwSwapBuffers(window);
        
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    printf("Goodbye!\n");
    
    return 0;
}

