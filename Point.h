// A 2-dimensional point class!
// Coordinates are double-precision floating point.
//class had point z added as a private variable as well as adding z as a argument for the default constructor mutators and accessors

#ifndef __POINT_H
#define __POINT_H

class Point {
    
private:
    double x, y, z;                //point z was added as the 3rd dimension point

public:
    // Constructors
    Point();                      // default constructor
    Point(double x, double y, double z);   //will now take z as a third argument  // two-argument constructor

    // Mutator methods
    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);                 //mutator z was added for the z
    double distanceTo(const Point& p1, const Point& p2)const ;

    // Accessor methods
    double getX() const;
    double getY() const;
    double getZ() const;                    //accessor get z was added for z
    
};

#endif // __POINT_H
