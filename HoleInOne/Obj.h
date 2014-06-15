//
//  Obj.h
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#ifndef __HoleInOne__Obj__
#define __HoleInOne__Obj__

#include "/opt/local/include/GLFW/glfw3.h"
#include "Helper.h"
#include "Vec3.hpp"

#include <iostream>

class Obj {
protected:
    int status;
    int pickedStatus = PICKED_NO;
    Vec3 v;
public:
    Obj();
    virtual void draw() = 0;
    void pick(int newStatus);
    int getPickStatus();
    void move(int direction);
};

#endif /* defined(__HoleInOne__Obj__) */
