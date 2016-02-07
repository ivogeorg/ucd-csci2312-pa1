//
//  area.cpp
//  PA1
//
//  Created by Scott Nedvesky on 2/6/16.
//  Copyright © 2016 Scott Nedvesky. All rights reserved.
//

#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

double computeArea(const Point &a, const Point &b, const Point &c)
{
    double A, B, C, S, Area;
    
    // get distance
    A = a.distanceTo(b);
    B = b.distanceTo(c);
    C = c.distanceTo(a);

    //Find S
    S = (A + B + C)/2;                   
    
    // Computer Area Forumula
    Area = sqrt((S*(S-A)*(S-B)*(S-C)));  
    
    return Area;
}
