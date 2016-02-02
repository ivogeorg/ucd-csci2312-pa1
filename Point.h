// A 3-dimensional point class!
// Coordinates are double-precision floating point.

#ifndef __POINT_H
#define __POINT_H

class Point {
    
private:
    double x, y, z;

public:
    // Constructors
    Point();                      // default constructor
    Point(double x, double y, double z);    // three-argument constructor

    // Mutator methods
	void setX(double newX) { newX = x };
	void setY(double newY) { newY = y };
	void setX(double newZ) { newZ = z };

    // Accessor methods
	double getX() const { return x };
	double getY() const { return y };
	double getZ() const { return z };
    
};

#endif // __POINT_H
