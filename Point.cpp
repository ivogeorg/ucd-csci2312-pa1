# include <iostream>
# include <cmath>
# include "Point.h"

using namespace std;

double Point::distanceTo(const Point& P2)const
{
  return sqrt(pow((P2.getX-x),2)+pow((P2.getY-y),2)+pow((P2.getZ-z),2);
};
