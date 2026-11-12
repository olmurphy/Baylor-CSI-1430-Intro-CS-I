/*
Author: Owen Murphy
Assignment Title: Area of Triangle
Assignment Description: Write a program that reads in points from a file
   and calculates and reports the area if it is a triangle
Due Date: 11/11/2019
Date Created: 11/07/2019
Date Last Modified: 11/11/2019
*/

#include "triangle.h"

double SideLengthTriangle(double x1, double y1, double x2, double y2) {
    return sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

double AreaOfTriangle(double a, double b, double c, double s) {
    assert(s >= 0 && s >= a && s >= b && s >= c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
