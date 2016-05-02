
// A 3-dimensional point class!
// Coordinates are double-precision floating point.
class Point {

private:
    double x;
    double y;
    double z;

public:
    // Constructors
    Point();                      // default constructor
    Point(double x, double y, double z);    // two-argument constructor

    // Destructor
    ~Point();

    // Mutator methods
    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);
    
    // Accessor methods
    double getX() const;
    double getY() const;
    double getZ() const;
    
};
```

We can _instantiate_, or create an instance of, our class anywhere in the rest of our code by calling any of the constructors we have defined:

```
Point myPoint;            // Calls Point::Point(). Notice the lack of parentheses!
Point myOtherPoint(5, 3); // Calls two-argument constructor Point::Point(double, double). Notice auto type conversion!
```

### Your Task

1.  Was forked and cloned. 

2.  3D was implemented and a source code (Point.cpp was created).

3.  Member function distanceTo was added

4.  area.cpp was made using Heron's formula

8.  CHanges were commited and pushed.

9.  ReadMe updated.
