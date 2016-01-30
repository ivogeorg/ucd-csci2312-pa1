## CSCI 2312: Programming Assignment 1

_working with objects_

* * *

C++ lets us program with _objects_. We describe objects in C++ by declaring and defining _classes_. We _declare_ our class's structure in a header file, just like in C, and _define_ it (that is, write the code that actually does the work) in a corresponding source code file.

Here is a sample header file <tt>Point.h</tt> that describes an object that represents a point in two-dimensional Euclidean space:

```c++
// A 2-dimensional point class!
// Coordinates are double-precision floating point.
class Point {

private:
    double x;
    double y;

public:
    // Constructors
    Point();                      // default constructor
    Point(double x, double y);    // two-argument constructor

    // Destructor
    ~Point();

    // Mutator methods
    void setX(double newX);
    void setY(double newY);

    // Accessor methods
    double getX() const;
    double getY() const;

};
```

We can _instantiate_, or create an instance of, our class anywhere in the rest of our code by calling any of the constructors we have defined:

```
Point myPoint;            // Calls Point::Point(). Notice the lack of parentheses!
Point myOtherPoint(5, 3); // Calls two-argument constructor Point::Point(double, double). Notice auto type conversion!
```

### Your Task

1.  Fork the [Github repository for CSCI 2312 PA1](https://github.com/ivogeorg/ucd-csci2312-pa1). This becomes your _remote_ repository, against which you will work. Then clone it to your local development environment (e.g. laptop). This becomes your _local_ repository against which you will develop. You will find the <tt>Point.h</tt> file for the 2D Point class, along with a test suite and a driver file <tt>main.cpp</tt>.

2.  Change the <tt>Point</tt> class to represent points in three (3) dimensions. Make sure to update the comments to match this change. Implement the class in a source file <tt>Point.cpp</tt>.

3.  Add a new member function to <tt>Point</tt> called <tt>distanceTo</tt>. This member function should accept as an argument a <u><tt>const Point &</tt></u> (a reference to a constant <tt>Point</tt>), and it should return a <tt>double</tt> that approximates the distance between the two points. Note that <tt>distanceTo</tt> is a _constant_ member function.

   If you find a square-root function useful for this, the C standard library has one, called <tt>sqrt()</tt>. The function takes a double and returns another double.

   To use it in your C++ code, you write
   ```c++
   #include <cmath>
   ```
   (This means, "Include the C math library header.") And then you are all set. Remember to always include your header files, for example,
   ```c++
   #include "Point.h"
   ```
   __after__ all the Standard Library headers.

4.  Create a new source file <tt>area.cpp</tt> and implement the following function:

   ```c++
   double computeArea(const Point &a, const Point &b, const Point &c);
   ```

   which takes by reference three constant <tt>Point</tt> objects, computes the area within the triangle defined by these points (hint: use [Heron's Formula](http://en.wikipedia.org/wiki/Heron%27s_formula)), and returns it as a double-precision floating point number.

5.  If you comfortable with the command line, compile these sources together like so:

   ```
   g++ -Wall main.cpp area.cpp Point.cpp PointTests.cpp ErrorContext.cpp -o ucd-csci2312-pa1
   ```

   Note:
   *   <tt>g++</tt> is the GNU C++ compiler.
   *   <tt>-Wall</tt> means "output ALL warnings." (If you see any warnings, be sure to fix them.)
   *   Next comes the list of source files. (You don't list header files here. They are included by the source files.) <tt>main.ccp</tt> is the program driver file. <tt>Point.cpp</tt> is your implementation of the 3D Point. <tt>area.cpp</tt> is your implementation of the computeArea function. <tt>PointTests.cpp</tt> contains the implementation of the test suite. <tt>ErrorContext.cpp</tt> implements a class holding testing information and used in the test suite.
   *   <tt>-o</tt> specifies the output file. In this case, we are making a program called <tt>ucd-csci2312-pa1</tt>.

   If you are using CLion, you can just go to Run-->Build. The project already supplies a CMakeLists.txt file, which is read by the cross-platform build tool [CMake](https://cmake.org/). CLion uses CMake to create a makefile for your architecture. Here is a short [tutorial](http://mrbook.org/blog/tutorials/make/) on makefile and the C++ build process. CMake uses the directives in the CMakeLists.txt and works with the specific build tool for your platform to create the makefile. The file looks like this

   ```
cmake_minimum_required(VERSION 3.3)
project(ucd_csci2312_pa1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        area.cpp
        Point.cpp
        Point.h
        PointTests.h
        PointTests.cpp
        ErrorContext.cpp
        ErrorContext.h)

add_executable(ucd_csci2312_pa1 ${SOURCE_FILES})
```

   For this project, all you need to do to run your Point code on CLion is to list all your *.cpp files as shown. Listing the headers as well doesn't hurt.

6.  Run the generated program:

   ```
./ucd_csci2312_pa1
```

   In CLion, you first have to build (Run-->Build) and then run (Run-->Run 'ucd_csci2312_pa1') your project. Any output will appear in the built-in console.

7.  This assigment is based on a test suite. The test suite is written not against the original assignment but against the finished assignment. So the first time you run it, it won't even compile. For example, the test suite assumes a 3D Point whereas the original assignment has only a 2D Point. 

   Test-driven development (TDD) means that you write your test code before you write the actual code it has to test. You will be doing TDD, except that you already have the test suite. The test suite is written in such a way that earlier tests are more basic and later tests require earlier tests to be running. The most basic test is usually called a "smoke test", so it's best to start there. Here is a recommended strategy for completing PA1:

   *   The test suite is in <tt>PointTests.h</tt> and <tt>PointTests.cpp</tt>. <tt>main.cpp</tt> runs the tests.
   *   Comment out all but the first test in those files.
   *   Read the error messages from the compiler and/or linker, and also the assignment requirements (this document).
   *   Implement enough functionality to pass the first test.
   *   Uncomment the next test from the driver and test suite files.
   *   Repeat the procedure until all tests pass. At this time you are done with programming.
   *   Change the comments where necessary.

   Note: If you see that CMake is complaining that it can't find some of its files (e.g. <tt>area.cpp</tt>), you should create them. To add them to your git _local_ repository, you need to execute the command
   ```
   git add area.cpp
   ```
   or, alternatively, in CLion, right-click on the new file, scroll down to __Git__ and then click __+ Add__.

8.  Commit all code changes to your _local_ repository, then push the changes to the default __master__ branch of your Github repository (aka _remote_ repository).

9.  Update the [README.md](https://github.com/ivogeorg/ucd-csci2312-pa1/edit/master/README.md) file in your _remote_ repository with a description of your 3D Point class. (Clicking on a file takes you to a view where you can edit it.) You can use this file as a guide. Use the [Github Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet) as a reference.

10. Coding style is important for your career. While this assignment is going to be graded strictly on passing the tests, subsequent assignments might also check for coding style. Here is a short C++ programming [style guide](http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cppstyle.html) you can use as a reference. Adopting a good style early on, when the assingment is small, will pay off greatly and very soon. 

### Grading

An autograding script will test your class on a variety of inputs and assign a grade based on the number of passed tests. (E.g. if your code passes 3 out of 6 test cases, your correctness score will be 50%). The test suite for PA1 has __56__ tests.

* * *

<font size="-1">ACKNOWLEDGEMENT: Modelled after CS11 Lab 1 at Caltech.</font>

<font size="-1">Some content Copyright (C) 2004-2010, California Institute of Technology.</font>
