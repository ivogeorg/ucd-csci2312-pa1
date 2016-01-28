#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

#include "Point.h"
#include "ErrorContext.h"
#include "PointTests.h"

using std::cout;
using std::endl;
using std::setprecision;

using Testing::ErrorContext;

#define DESC(x) desc(x, __LINE__)  // ugly hack, but saves some time

// smoke test
void test_point_smoketest(ErrorContext &ec) {
    bool pass;

    ec.DESC("--- Test - Point - Smoketest ---");

    ec.DESC("constructor, dimensionality, destructor");
    pass = true;
    for (int i = 0; i < 10; i ++) {

        // Construct a Point
        // At the end of the block, destructor will be called
        Point p(1, 2, 3);

        pass = (p.getX() == 1 && p.getY() == 2 && p.getZ() == 3);
        if (!pass) break;
    }
    ec.result(pass);


    ec.DESC("constructor, large values");
    pass = true;
    for (int i = 0; i < 10; i ++) {

        // Construct a Point
        // At the end of the block, destructor will be called
        Point p(5000000002, 3000000001, 4111111110);

        pass = (p.getX() == 5000000002 && p.getY() == 3000000001 && p.getZ() == 4111111110);
        if (!pass) break;
    }
    ec.result(pass);
}

// get/set
void test_point_getset(ErrorContext &ec, unsigned int numRuns) {
    bool pass;

    // Run at least once!!
    assert(numRuns > 0);

    ec.DESC("--- Test - Point - Get/set ---");

    for (int run = 0; run < numRuns; run++) {

        ec.DESC("default constructor initializes to 0");
        {
            Point p;

            pass = (p.getX() == 0 && p.getY() == 0 && p.getY() == 0);

            ec.result(pass);
        }

        ec.DESC("set on a default constructed point");
        {
            Point p;

            p.setX(6.5); p.setY(5.67); p.setZ(4.63);

            pass = (p.getX() == 6.5 && p.getY() == 5.67 && p.getZ() == 4.63);

            ec.result(pass);
        }

        ec.DESC("set on a non-default constructed point");
        {
            Point p(10, 14, 23);

            p.setX(6.5); p.setY(5.67); p.setZ(4.63);

            pass = (p.getX() == 6.5 && p.getY() == 5.67 && p.getZ() == 4.63);

            ec.result(pass);
        }
    }
}

// figures in space
void test_point_figures(ErrorContext &ec, unsigned int numRuns) {
    bool pass;

    // Run at least once!!
    assert(numRuns > 0);

    ec.DESC("--- Test - Point - Figures ---");

    for (int run = 0; run < numRuns; run++) {

        ec.DESC("2d triangle");
        {
            Point p1(0, 0, 0), p2(3, 0, 0), p3(0, 4, 0);

            double diff = computeArea(p1, p2, p3) - 6.0;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("line");
        {
            Point p1(0, 0, 0), p2(3, 0, 0), p3(3, 0, 0);

            double diff = computeArea(p1, p2, p3) - 0.0;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("point");
        {
            Point p1(0, 0, 0), p2(0, 0, 0), p3(0, 0, 0);

            double diff = computeArea(p1, p2, p3) - 0.0;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("3d triangle");
        {
            Point p1(1, 0, 0), p2(0, 1, 0), p3(0, 0, 1);

            double diff = computeArea(p1, p2, p3) - 0.866025;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("3d negative");
        {
            Point p1(-1, 0, 0), p2(0, -1, 0), p3(0, 0, -1);

            double diff = computeArea(p1, p2, p3) - 0.866025;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("3d negative");
        {
            Point p1(-1, -1, -1), p2(-1, -1, -1), p3(-1, -1, -1);

            double diff = computeArea(p1, p2, p3) - 0.0;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("2d negative");
        {
            Point p1(0, 0, 0), p2(-3, 0, 0), p3(0, -4, 0);

            double diff = computeArea(p1, p2, p3) - 6.0;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("2d small");
        {
            Point p1(0, 0, 0), p2(10000, 0, 0), p3(0, .00001, 0);

            double diff = computeArea(p1, p2, p3) - 0.05;

            pass = diff * diff < POINT_SQUARE_ERROR;
            ec.result(pass);
        }

        ec.DESC("2d large");
        {
            Point p1(0, 0, 0), p2(3000000, 0, 0), p3(0, 4000000, 0);

            double diff = computeArea(p1, p2, p3) - 6e+12;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }

        ec.DESC("3d random");
        {
            Point p1(1, -64, -23), p2(-.004, 107, -42.5), p3(-34.6, -4000000.7, 3600.8);

            double diff = computeArea(p1, p2, p3) - 38741777.098192796111;

            pass = diff * diff < POINT_SQUARE_ERROR;

            ec.result(pass);
        }
    }
}

// point-based area
void test_area(ErrorContext &ec, unsigned int numRuns) {
    bool pass;

    // Run at least once!!
    assert(numRuns > 0);

    ec.DESC("--- Test - Area ---");

    for (int run = 0; run < numRuns; run++) {

        ec.DESC("3 points, unaligned");
        {
            Point p1(0, 0, 0), p2(3, 0, 0), p3(0, 4, 0);

            pass = (computeArea(p1, p2, p3) == 6);

            ec.result(pass);
        }

        ec.DESC("3 points, 2 of them the same");
        {
            Point p4(0, 0, 0), p5(3, 0, 0), p6(3, 0, 0);

            pass = (computeArea(p4, p5, p6) == 0);

            ec.result(pass);
        }

        ec.DESC("3 points, 3 of them the same");
        {
            Point p7(0, 0, 0), p8(0, 0, 0), p9(0, 0, 0);

            pass = (computeArea(p7, p8, p9) == 0);

            ec.result(pass);
        }

        ec.DESC("3 points, unaligned, negative");
        {
            Point p1(0, 0, 0), p2(-3, 0, 0), p3(0, -4, 0);

            pass = (computeArea(p1, p2, p3) == 6);

            ec.result(pass);
        }

        ec.DESC("3 points, unaligned, negative, shifted");
        {
            Point p1(-10, -10, -10), p2(-13, -10, -10), p3(-10, -14, -10);

            pass = (computeArea(p1, p2, p3) == 6);

            ec.result(pass);
        }
    }
}
