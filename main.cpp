// main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "ErrorContext.h"
#include "PointTests.h"

using std::cout;
using std::endl;

using namespace Testing;

int main() {

    const int NumIters = 3;

    cout << endl << "Testing PA1!!" << endl << endl;

    cout << "NOTE:  If you see any memory errors, you MUST fix them!" << endl;
    cout << "       Tests intentionally invoke destructors after they complete,"
    << endl;
    cout << "       so if you see a seg-fault after a passed test, it is"
    << endl;
    cout << "       probably a bug in your destructor." << endl;

    cout << endl;

    ErrorContext ec(cout);

    // point tests
    test_point_smoketest(ec);
    test_point_getset(ec, NumIters);
    test_point_figures(ec, NumIters);

    // area tests
    test_area(ec, NumIters);


    return 0;
}
