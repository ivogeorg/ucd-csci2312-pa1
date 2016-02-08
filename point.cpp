#include "Point.h"
#include <cmath>


    Point::Point()
    {
       x = 0;                   //sets all variables to a default value of 0 x = 0
        y = 0;                  //sets y = 0
        z = 0;                  //sets z = 0
    }

    Point::Point(double x, double y, double z)
    {
       setX(x);                 //will cal function to set x a new value//
        setY(y);                //will call function to set y a new value
        setZ(z);                //will call the funtion to set z a new value
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

double Point::distanceTo(const Point &p1, const Point &p2) const
{
    double tempX = (p1.x - p2.x);
    double tempY = (p1.y - p2.y);
    double tempZ = (p1.z - p2.z);

    tempX = pow(tempX,2);
    tempY = pow(tempY,2);
    tempZ = pow(tempZ,2);

    return std::sqrt(tempX + tempY + tempZ);

}
