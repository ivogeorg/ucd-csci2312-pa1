//CSC 2312
//Homework PA1
//Febuary 7, 2016
//Function to Compute Area

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
    
    // Computer Heron's Area Forumula
    Area = sqrt((S*(S-A)*(S-B)*(S-C)));  
    
    return Area;
}
