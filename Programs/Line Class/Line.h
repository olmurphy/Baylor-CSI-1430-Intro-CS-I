/*
Author: Owen Murphy
Assignment Title: Line Class
Assignment Description: Write a source cpp file for a line class that has
methods as described on the wiki page
Due Date: 11/15/2019
Date Created: 11/11/2019
Date Last Modified: 11/15/2019
*/

#ifndef Line_H_INCLUDED
#define Line_H_INCLUDED

#include <ostream>
#include <iostream>
#include <cassert>
using namespace std;

struct Point {
    double x;
    double y;
    
    Point (double a = 0, double b = 0) {
        x = a;
        y = b;
    }
    
    void display (ostream& os) {
        os << "(" << x << ", " << y << ")";
    }
};

class Line {
private:
    Point p1, p2;
    
public:
    Line();
    Line(Point, Point);

    void setFirstPoint(Point);
    void setSecondPoint(Point);

    Point getFirstPoint() const;
    Point getSecondPoint() const;

    bool slope(double& m) const;
    bool yIntercept(double& b) const;

    bool isParallel(Line) const;
    bool isCollinear(Line) const;
    bool isPerpendicular(Line) const;

    Point intersect(Line) const;

    void display(ostream&) const;
};

#endif /* Line_H_INCLUDED */
