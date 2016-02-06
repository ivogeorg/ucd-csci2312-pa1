//
//  area.cpp
//  point
//
//  Created by Maxim Anaya on 2/5/16.
//  Copyright © 2016 Maxim Anaya. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include "Point.h"


double computeArea(const Point &a, const Point &b, const Point &c)
{
    double AB = a.distanceTo(b);
    double BC = b.distanceTo(c);
    double CA = c.distanceTo(a);
    
    // part of Heron's formula
    double s = (AB + BC + CA) / 2;
    
    // Heron's formula
    return sqrt(s * (s - AB) * (s - BC) * (s - CA));
}