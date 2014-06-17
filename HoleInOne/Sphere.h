//
//  Sphere.h
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#ifndef __HoleInOne__Sphere__
#define __HoleInOne__Sphere__

#include <iostream>
#include "Obj.h"
#include "vec3.hpp"

class Sphere : public Obj {
    double radius;
public:
    Sphere(Vec3 vec,double r);
    void draw();
    void DrawSphere(const Vec3& ctr, double r);
    float getRadius();
};

#endif /* defined(__HoleInOne__Sphere__) */
