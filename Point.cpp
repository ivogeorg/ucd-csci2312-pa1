//
//  Point.cpp
//  PA1
//
//  Created by Scott Nedvesky on 2/6/16.
//  Copyright © 2016 Scott Nedvesky. All rights reserved.
//

#include "Point.h"
#include <cmath>

Point::Point() : x(NULL), y(NULL), z(NULL)
{
    setX(x);
    setY(y);
    setZ(z);
}

Point::Point(double newX, double newY, double newZ)
{
    x = newX;
    y = newY;
    z = newZ;
}

void Point::setX(double newX)
{
    x = newX;
}

void Point::setY(double newY)
{
    x = newY;
}

void Point::setZ(double newZ)
{
    x = newZ;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

double Point::distanceTo(const Point &newp) const
{
    double distx = newp.getX() -x;
    double disty = newp.getY() -y;
    double distz = newp.getZ() -z;
    double total;
    
    total = sqrt((distx*distx)+(disty*disty)+(distz*distz));
    
    return total;
    
    
}
