//
//  Pyramid.h
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#ifndef __HoleInOne__Pyramid__
#define __HoleInOne__Pyramid__

#include <iostream>
#include "Obj.h"
#include "vec3.hpp"

#endif /* defined(__HoleInOne__Pyramid__) */

class Pyramid : public Obj {
public:
    Pyramid(Vec3 vec);
    void draw();
};