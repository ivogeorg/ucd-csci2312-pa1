#include <iostream>
#include <cmath>
#include "Point.h"

double computeArea(const Point &a, const Point &b, const Point &c);

double computeArea(const Point &a, const Point &b, const Point &c)
{
    double semiPerimeter;                       //creates a double value that hold the value for semiprimeter of the cordinates
    double Area;                                //variable that holds value for area from the semi perimeter you can calculate the area
    double tempA = a.distanceTo(a,b);           //pass 1 will hold distance to point a and point b
    double tempB = b.distanceTo(b,c);           //pass 2 will hold the distance to point b to c
    double tempC = c.distanceTo(a,c);           //pass 3 will hodl the distance to point a to c

    semiPerimeter = (tempA + tempB + tempC)/ 2.0;   //calculates the semi primeter of the points  s= {a+b+c}/2}.

    Area = std::sqrt(semiPerimeter*(semiPerimeter - tempA)*(semiPerimeter - tempB)*(semiPerimeter - tempC));
    //will calculate the area using the semiperimeter
    // A = sqrt{s(s-a)(s-b)(s-c)},
    return Area;                                    //will return the double value for the computeArea
}