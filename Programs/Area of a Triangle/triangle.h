/*
Author: Owen Murphy
Assignment Title: Area of Triangle
Assignment Description: Write a program that reads in points from a file
   and calculates and reports the area if it is a triangle
Due Date: 11/11/2019
Date Created: 11/07/2019
Date Last Modified: 11/11/2019
*/

#ifndef triangle_H_INCLUDED
#define triangle_H_INCLUDED

#include <cmath>
#include <ostream>
#include <cassert>
using namespace std;

/*
description:
    calculates the side length of a triangle given to points as the parameters
        and returns the value of the computation
return:
    returns the length of each side of a triangle
precondition:
    their are two vertices passed in as parameters
    Four double values exist
postcondition:
    the values of the points passed in as parameters are unchanges
    the length of two points is returned
*/
double SideLengthTriangle(double, double, double, double);

/*
description:
    Calculates the area of the triangle given the 3 side lengths and the
        perimters of the triangle and returns the value of the computation
return:
    returns the area of the triangle
precondition:
    the three side lengths and the perimeter of the triangle are passed in
        as parameters
    four double values exist
postcondition:
    the values passed in as parameters are unchanged
    the area of the triangle is returned
*/
double AreaOfTriangle(double, double, double, double);

#endif /* triangle_H_INCLUDED */

