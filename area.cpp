// Area for within the triangle
// Created by HosZul on 2/7/2016.
//

#include <stdio.h>
#include <cmath>
#include "Point.h"

double computeArea(const Point &a, const Point &b, const Point &c)
    {
        double AB = a.distanceTo(b);
        double BC = b.distanceTo(c);
        double CA = c.distanceTo(a);

        // Heron's Formula in Task 4
        double side = (AB + BC + CA)/2;
        return sqrt(side * (side - AB) * (side -BC) * (side - CA));
    }