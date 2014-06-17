//
//  Obj.cpp
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#include "Obj.h"

Obj::Obj() {
    status = STOPPED;
}

void Obj::pick(int newStatus) {
    this->pickedStatus = newStatus;
}

int Obj::getPickStatus() {
    return this->pickedStatus;
}

void Obj::move(int direction) {
    switch (direction) {
        case GLFW_KEY_W:
            this->v.p[0] += 0.2;
            break;
        case GLFW_KEY_S:
            this->v.p[0] -= 0.2;
            break;
        case GLFW_KEY_A:
            this->v.p[2] -= 0.2;
            break;
        case GLFW_KEY_D:
            this->v.p[2] += 0.2;
            break;
        default:
            break;
    }
}

Vec3 Obj::getV() {
    return this->v;
}

void Obj::setV(Vec3 vec) {
    this->v = vec;
}

Vec3 Obj::getVelocity() {
    return this->velocity;
}

void Obj::setVelocity(Vec3 vec) {
    this->velocity = vec;
}
