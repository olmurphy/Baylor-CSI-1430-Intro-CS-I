/*
 Author: Owen Murphy
 Assignment Title: Quadratic Formula
 Assignment Description: Write a program that takes in 3 integers and
    calculates the root(s).
 Due Date: 09/16/2019
 Date Created: 09/13/2019
 Date Last Modified: 09/15/2019
 */

/*
 Data Abstraction:
    Output file stream is opened
    integers a, b, and c are declared to get input from user. Variable d is
    declared to find discriminant and numRoots is declared to determines the
    number of roots
 Input:
    The program reads input a, b, and c from user assigns the integers to
    their respective variables
 Process:
    Calculate the discriminate and to see number of real roots, if any
        If the discrimnate is negative then "NO REAL ROOTS" is printed to
        the screen
    The root(s) is/are calculated if exist
 Output:
    Print the "NO REAL ROOTS" if none and print root if one and print the two
        roots from least to greates if there is two.
 Assumptions:
    It is assumed the user only wants to solve one formula at a time
    It is assumed the user only wants real roots to the formula
    It is assumed the user will input the data correctly
 */


#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
    
    int a, b, c, numRoots;
    double d, r1, r2;
    
    cin >> a >> b >> c;
    
    d = 0;
    numRoots = 0;
    
    d = (pow(b, 2) - 4.0 * a * c);
    
    if (d == 0) {
        numRoots = 1;
    }
    else {
        //false block
    }
    if (d > 0) {
        numRoots = 2;
    }
    else {
        // false block
    }
    
    cout << fixed << setprecision(2);
    if (numRoots == 0) {
        cout << "NO REAL ROOTS" << endl;
    }
    else {
        r1 = (-b - sqrt(d)) / (2.0 * a);
        r2 = (-b + sqrt(d)) / (2.0 * a);
    }
    if (numRoots > 0) {
        cout << r1 << "  ";
        if (numRoots == 2) {
            cout << r2 << endl;
        }
    }
    
    
    
    
    cout << "*** Start Extra Credit ***" << endl;
    
    // <Extra Credit Output>
    
    double x, y;
    x = (-b) / (2.0 * a);
    y = ((a * pow(x, 2)) + (b * x) + c);
    
    cout << "Vertex = (" << x << ", " << y << ")" << endl;
    
    cout << "*** End Extra Credit ***" << endl;
    
    
    return 0;
}
