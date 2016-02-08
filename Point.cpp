// For Points in 3D and Task #2
// Created by HosZul on 2/7/2016.
//

#include <cmath>
#include "Point.h"

// Constructors set equal to zero
Point::Point()
    {
        x = 0;
        y = 0;
        z = 0;
    }

Point::Point(double X, double Y, double Z)
    {
        x = X;
        y = Y;
        z = Z;
    }

void Point:: setX(double newX)
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

// Accessor Poits
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

// Distance for Task 2
double Point::distanceTo(const Point &other) const
    {
      // Heron's Formula
        return sqrt(pow(x-other.getX(),2)+ pow(y-other.getY(),2)+pow(z-other.getZ(),2));
    }
