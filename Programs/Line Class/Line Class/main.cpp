/*
 Author: Owen Murphy
 Assignment Title: Line Class
 Assignment Description: Write a source cpp file for a line class that has
    methods as described on the wiki page
 Due Date: 11/22/2019
 Date Created: 11/11/2019
 Date Last Modified: 11/22/2019
 */

/*
 Data Abstraction:
    string line to store each line and token to store each part of the line
    two stringstreams ss to store the full line to read from and numss for
        purposes of reach a number that is not 1, or -1
    double a, b, and c to store the coefficients of the line equation
    int sign, to indicate if a negative was number was preceded by a negative
        if so store -1 to use for later purposes in multiplication
    int left side, to indicate if the left side of the equation has been
        reached
    double m, and y to store the slope and y intercept respectively
    2 line objects to store the points of the two lines
 Input:
    read the two lines from standard input
    then while reading each line, read from a string stream each string of
        to evaluate the equation
 Process:
    While reading in from each input, determine what the input is using
        multiple if statements
    The different conditions that could be are x, #x, -#x, y, #y, -#y, #, =, -,
        or a plus sign. So with each sign determine what the equation is from
        there
 Output:
    Output the solution of the 2 lines, if not collinear and not parallel,
        print the intersection of the two lines
 Assumptions:
    It is assumed that the input data is valid input
    It is assumed that the input is only two equations
 */

#include <iostream>
#include <string>
#include <sstream>
#include "Line.h"
#include <iomanip>
#include <ios>

int main() {
    
    // Data Abstraction
    string line, token;
    stringstream ss;
    stringstream numss;
    double a, b, c;
    int    sign;
    int    leftSide;
    double m, y;
    Line line1, line2;
    
    // User Input
    for (int i = 0; i < 2; ++i) {
        getline(cin, line);
        ss.clear();
        ss << line;
        leftSide = 1;
        sign = 1;
        a = b = c = 0;
        
        // Data Processing
        while(ss >> token) {
            if(token.find('x') != string::npos) {
                if(token.size() == 1) {
                    a = 1 * sign * leftSide;
                    sign = 1;
                }
                else if(token.size() == 2 && token.at(0) == '-'){
                    a = -1 * sign * leftSide;
                    sign = 1;
                }
                else {
                    numss.clear();
                    numss.str(token.substr(0, token.size() - 1)); // get rid
                    numss >> a;                                   // of x
                    a *= sign * leftSide;
                    sign = 1;
                }
            }
            else if (token.find('y') != string::npos) {
                if(token.size() == 1) {
                    b = 1 * sign * leftSide;
                    sign = 1;
                }
                else if (token.size() == 2 && token.at(0) == '-') {
                    b = -1 * sign * leftSide;
                    sign = 1;
                }
                else {
                    numss.clear();
                    numss.str(token.substr(0, token.size() - 1));
                    numss >> b;
                    b*= sign * leftSide;
                    sign = 1;
                }
            }
            else if(token == "=") {
                leftSide = -1;
            }
            else if(token == "-") {
                sign = -1;
            }
            else if(token != "+"){
                numss.clear();
                numss.str(token);
                numss >> c;
                c *= sign * leftSide * -1;
                sign = 1;
            }
        }
        
        
        if (b != 0) {
            y = c / b;
            m = -1 * a / b;
    
            if (i == 0) {
                line1.setFirstPoint(Point(2, m * 2 + y));
                line1.setSecondPoint(Point(3, m * 3 + y));
            }
            else {
                line2.setFirstPoint(Point(2, m * 2 + y));
                line2.setSecondPoint(Point(3, m * 3 + y));
            }
        }
        else if(b == 0) {
            if (i == 0) {
                line1.setFirstPoint(Point(c, 1));
                line1.setSecondPoint(Point(c, -1));
            }
            else {
                line2.setFirstPoint(Point(c, 1));
                line2.setSecondPoint(Point(c, -1));
            }
        }
        else {
            if (i == 0) {
                line1.setFirstPoint(Point(c, -1));
                line1.setSecondPoint(Point(c, 1));
            }
            else {
                line2.setFirstPoint(Point(c, -1));
                line2.setSecondPoint(Point(c, 1));
            }
        }
    }
    
    // Output
    if (!(line1.isParallel(line2) || line1.isCollinear(line2))) {
        cout << fixed << setprecision(3);
        cout << "SOLUTION: ";
        line1.intersect(line2).display(cout);
        cout << endl;
    }
    else {
        cout << "NO SOLUTION" << endl;
    }
    return 0;
}
