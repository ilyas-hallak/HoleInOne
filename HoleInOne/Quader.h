//
//  Quader.h
//  HoleInOne
//
//  Created by Ilyas Hallak on 14.06.14.
//  Copyright (c) 2014 Ilyas Hallak. All rights reserved.
//

#ifndef __HoleInOne__Quader__
#define __HoleInOne__Quader__

#include <iostream>
#include "Obj.h"
#include "vec3.hpp"

class Quader : public Obj {
public:
    Quader(Vec3 vec);
    void draw();
};

#endif /* defined(__HoleInOne__Quader__) */
