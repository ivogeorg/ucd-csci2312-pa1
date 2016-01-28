#ifndef POINTTESTS_H
#define POINTTESTS_H

#include "Point.h"
#include "ErrorContext.h"

using Testing::ErrorContext;


const double POINT_SQUARE_ERROR = 0.00001;

// - - - - - - - - - Tests: class Point - - - - - - - - - -

// smoke test
void test_point_smoketest(ErrorContext &ec);

// get/set
void test_point_getset(ErrorContext &ec, unsigned int numRuns);

// figures in space
void test_point_figures(ErrorContext &ec, unsigned int numRuns);

// - - - - - - - - - Tests: Area - - - - - - - - - -

// forward declaration of computeArea
double computeArea(const Point &p1, const Point &p2, const Point &p3);

// point-based area
void test_area(ErrorContext &ec, unsigned int numRuns);


#endif // POINTTESTS_H
