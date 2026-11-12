/*
Author: Owen Murphy
Assignment Title: Line Class
Assignment Description: Write a source cpp file for a line class that has
methods as described on the wiki page
Due Date: 11/22/2019
Date Created: 11/11/2019
Date Last Modified: 11/22/2019
*/

#include "Line.h"

/*
Description:
    Default Constructor that creates the objects setting the values of line
        class of struct's points to (0, 0) and (1, 1)
Return:
    no return type for a default constructor
Precondition:
    takes in as parameters the class data members which are two points
Postcondition:
    the values of the data members are initialized to (0, 0) and (1, 1)
*/
Line::Line() {
    p1.x = 0;
    p1.y = 0;
    p2.x = 1;
    p2.y = 1;
}

/*
Description:
    Custom constructor that sets the 2 points on the line to the points passed
        in as parameters
Return:
    no return type for a custom constructor
Precondition:
    Takes in the two points points as parameters as well as the private data
        members
    the values exist
Postcondition:
    the values of the private data members are changed to the values of points
        passed in as parameters
*/
Line::Line(Point a, Point b) {
    p1 = a;
    p2 = b;
}

/*
Description:
    The method sets the coordinates of the first point of the line
Return:
    type void return, does not return anything
Precondition:
    A point object is passed in as a parameter
    the value exists
Postcondition:
    the first point of the line is set to the point passsed in as a parameter
*/
void Line::setFirstPoint(Point a) {
    p1 = a;
}

/*
Description:
    the method sets the second point of the line to the point passed is as a
        parameters
Return:
    type void return type, does not return anything
Precondition:
    A point object is passed in as a parameter
    the value exists
Postcondition:
    the values of second point is changed to the point passed passeed in
*/
void Line::setSecondPoint(Point a) {
    p2 = a;
}

/*
Description:
    The method returns the first point of the line allowing for accessing
        methods of the struct point
Return:
    returns point p1
Precondition:
    the line object private data memebers are passed in as parameters
Postcondition:
    the method does not change values and returns the first point
*/
Point Line::getFirstPoint() const {
    return p1;
}

/*
Description:
    the method returns the second point
Return:
    returns the second point
Precondition:
    takes in line object private data members as parameters
Postcondition:
    the values of the data members do not change
*/
Point Line::getSecondPoint() const {
    return p2;
}

/*
Description:
    the method returns true if the line has a slope
    also changes the pass by refernce by calculating the slope if it does have
        a slope
Return:
    returns true if slope and false otherwise
Precondition:
    the pass by reference is passed in as a parameter
Postcondition:
    the value of the private data members are unchanged
*/
bool Line::slope(double& m) const {
    bool hasSlope = false;
    hasSlope = (p1.x != p2.x);
    if (hasSlope) {
        m = (p2.y - p1.y) / (p2.x - p1.x);
    }
    
    return hasSlope;
}

/*
Description:
    The returns true if the line has a y intercept, false otherwise
    also calculates the y intercept if line has a slope by calling slope method
Return:
    returns true if y intercept, false otherwise
Precondition:
    the pass by reference is passed in a as a parameter
Postcondition:
    the values of the private data members are unchanged
    the value of b is changed if the y intercept exists
*/
bool Line::yIntercept(double& b) const {
    // y = mx + b
    // b = y - mx
    bool has_y_inter = false;
    double m;
    if (slope(m)) {
        has_y_inter = true;
        b = p1.y - (m * p1.x);
    }
    
    return has_y_inter;
}

/*
Description:
    the returns true if the lines are parallel and false if not by calling the
        slope function
Return:
    return true if parallel and false otherwise
Precondition:
    takes in a constant line object to compare the slopes
    the value exists
Postcondition:
    the value of the private data members are unchanged
*/
bool Line::isParallel(const Line otherLine) const {
    double m1, m2;
    bool parallel = false;
    
    if (otherLine.slope(m2) && slope(m1)) {
        parallel = (m2 == m1);
    }
    if (!otherLine.slope(m2) && !slope(m1)) {
        parallel = true;
    }
    
    return parallel;
}

/*
Description:
    returns if the two lines are collinear, i.e. the two lines are the same
        line just as different points
Return:
    return true if collinear and false otherwise
Precondition:
    takes in a line object
    the value exists
Postcondition:
    the value of the private data members are unchanged as well as the
        parameters passed in
*/
bool Line::isCollinear(Line otherLine) const {
    double m1, m2, b1, b2;
    bool collinear = false;
    if (slope(m1) && otherLine.slope(m2)) {
        yIntercept(b1);
        otherLine.yIntercept(b2);
        collinear = (b1 == b2 && m1 == m2);
    }
    return collinear;
}

/*
Description:
    method returns true if perpindicular and false otehrwise
    determines the perpindicular by calling on slope and comparing the negative
        reciprocals of the slopes
Return:
    returns true if perpindicular and false otherwise
Precondition:
    the line object is passed in as a parameters
    the value exists
Postcondition:
    the value of the private data member and the line object passed in are
        unchanged
*/
bool Line::isPerpendicular(Line otherLine) const {
    double m1, m2;
    otherLine.slope(m2);
    slope(m1);
    return (((-1.0) * (1 / m1)) == m2);
}

/*
Description:
    The method determines intersection by calling the slope and
        y intercept method
Return:
    returns the points at which the two lines intersect at
Precondition:
    a line object is passed in as a parameter
    the value exists
Postcondition:
    the values of the private data member and the parameter passed in are
        unchanged
*/
Point Line::intersect(Line otherLine) const {
    Point p;
    double m1, m2, b1, b2;
    
    if (slope(m1) && otherLine.slope(m2)) {
        yIntercept(b1);
        otherLine.yIntercept(b2);
        p.x = (b2 - b1) / (m1 - m2);
        p.y = m1 * p.x + b1;
    }
    else if (slope(m1)) {
        p.x = otherLine.getFirstPoint().x;
        if (yIntercept(b1)) {
            p.y = m1 * p.x + b1;
        }
        else {
            p.y = m1 * p.x;
        }
    }
    else if (otherLine.slope(m2)) {
        p.x = getFirstPoint().x;
        if (otherLine.yIntercept(b2)) {
            p.y = p.x + b2;
        }
        else {
            p.y = p.x;
        }
    }
    
    return p;
}

/*
Description:
    method used to display the equation of a line by calling the slope and
        intercept methods
    outputs to the ostream as a pass by reference
Return:
    void return type, does not return anything
Precondition:
    the ostream as a pass by reference is returned
Postcondition:
    the value of os is changed, and the value of the private data members are
        unchanged
*/
void Line::display(ostream& os) const {
    // y = mx + b;
    double m, b;
    if (slope(m)) {
        os << "y =";
        if (m == 1.0) {
            os << " " << "x";
        }
        else if (m == -1.0) {
            os << " -x";
        }
        else {
            os << " " << m << "x";
        }
        
        if (yIntercept(b)) {
            if (b < 0) {
                os << " " << b;
            }
            else if (b > 0) {
                os << " + " << b;
            }
        }
    }
    else {
        os << "x = " << p1.x;
    }
}
