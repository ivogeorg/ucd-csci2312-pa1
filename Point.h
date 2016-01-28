// A 2-dimensional point class!
// Coordinates are double-precision floating point.

#ifndef __point_h
#define __point_h

class Point {
private:
    double x, y;

public:
    // Constructors
    Point();                      // default constructor
    Point(double x, double y);    // two-argument constructor

    // Mutator methods
    void setX(double newX);
    void setY(double newY);

    // Accessor methods
    double getX() const;
    double getY() const;
};

#endif // __point_h