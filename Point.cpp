//Scott Nedvesky
//CSC 2312
//Homework PA1
//Febuary 7, 2016
//Functions to Compute Distance
//Point.cpp

#include "Point.h"
#include <cmath>

Point::Point()
{
    x=0;
    y=0;
    z=0;
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
    y = newY;
}

void Point::setZ(double newZ)
{
    z = newZ;
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

double Point::distanceTo(const Point &other) const
{
    double distx = other.getX() -x;
    double disty = other.getY() -y;
    double distz = other.getZ() -z;
    double total;
    
    total = sqrt(pow(distx, 2) + pow(disty, 2) + pow(distz, 2));
    
    
    return total;
    
    
}
