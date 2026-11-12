/*
 Author: Owen Murphy
 Assignment Title: Geometry
 Assignment Description: Write a program that takes into 2 coordinates and
    returns whether they are in the area bounded by the curve and the first
    quadrant
 Due Date: 09/18/2019
 Date created: 09/17/2019
 Date Last Modified: 09/18/2019
*/

/*
 Data Abstraction:
    Declare the x and y coordinates and a boolean value inTriangle to run the
    if statement if true else it is false
 Input:
    Prompt the user to enter two numbers
 Process:
    Test if coordinates are in the region
 Output:
    If they are in region print to screen that the coordinates are in the
    triangle if no in region then print they are not in triangle
 Assumptions:
    It is assumed that the user will input a double or integer variable and
    not a char or string
 */

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;
int main() {
    
    // Data Abstraction
    int x, y;
    bool inTriangle = false;
    
    // Prompt
    cout << "Enter a point's x- and y-coordinates: ";
    
    // Input
    cin >> x >> y;
    cout << x << " " << y << endl;
    
    // Process
    if ((x > 200) || (x < 0) || (y > 100) || (y < 0)) {
        inTriangle = false;
    }
    else {
        if (y <= ((-1.0/2.0) * x) + 100) {
            inTriangle = true;
        }
    }
    
    // Output
    if (inTriangle) {
        cout << "The point (" << x << ", " << y << ") is in the";
        cout << " triangle." << endl;
    }
    else {
        cout << "The point (" << x << ", " << y << ") is NOT in the triangle.";
        cout << endl;
    }
    
    cout << endl << endl << "*** Start Extra Credit ***" << endl << endl;;
    
    double d;
    
    d = sqrt(pow(x, 2) + pow(y, 2));
    
    // <Extra Credit Output>
    cout << fixed << setprecision(2);
    cout << "Distance to the origin = " << d << endl << endl;
    
    cout << "*** End Extra Credit ***" << endl;
    
    return 0;
}
