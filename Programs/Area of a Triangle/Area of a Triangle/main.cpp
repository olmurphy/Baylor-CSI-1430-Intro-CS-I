/*
 Author: Owen Murphy
 Assignment Title: Area of Triangle
 Assignment Description: Write a program that reads in points from a file
    and calculates and reports the area if it is a triangle
 Due Date: 11/11/2019
 Date Created: 11/07/2019
 Date Last Modified: 11/11/2019
 */

/*
 Data Abstraction:
    string fileName to store the name of the file
    ifstream inputFile to store data from file into the stream
    double x1, y1, x2, y2, x3, and y3 to store the coordinates of the triangle
    integer count to keep track of the number of triangles there are
    double maxArea and minArea to store the maximum and mininum area
    double minP and maxP to store the maximum and minimum perimeter
    double a, b, and c to store the current lengths of the three lines and
        double c to store the current perimeter
    double area to store the current area of the triangle
    double sumArea and sumP to store the sum of all the areas and perimeters
    integer pCount to count to store number of times perimeter is calculated
 Input:
    Read in the fileName and keep asking if file did not open
    Read in the first line and throw it away
    Then start reading in the number for the coordinates until no more
        coordinates for file exists
 Process:
    Read and store each coordinate of a triangle, calculate all three side
        lengths of the triangle by calling SideLengthTriangle function with
        the two points passed in as parameters
    Calculate the perimater of the triangle
    Add the perimater and area of triangle into their respective sum variables
    Find the minimum and maximum area by using comparison
 Output:
    Output the three vertices and output the area of triangle if it is greater
        than 0, else output that it is not a triangle
 Assumptions:
    It is assumed that the data within the file is valid input data
    It is assumed that the data is formated like the exampled
 */

#include <iostream>
#include <string> // string
#include <fstream> // ifstream
#include "triangle.h"
#include <iomanip> // fixed, setprecision(), setw()
using namespace std;

int main() {
    
    // Data Abstraction
    string fileName;
    ifstream inputFile;
    double x1, y1, x2, y2, x3, y3;
    int count = 0;
    double maxArea, minArea, minP, maxP;
    double a, b, c, s;
    double area;
    double sumArea = 0, sumP = 0;
    
    // User Input
    do {
        cout << "Enter Name Of Data File: ";
        cin >> fileName;
        cout << fileName << endl;
        inputFile.open(fileName);
        if (!inputFile) {
            cout << "ERROR: File Not Open." << endl;
        }
    } while (!inputFile);
    
    getline(inputFile, fileName); // skips the first line of the data file
    
    int perCount = 0; // count number of times perimeter is calculated
    
    // Data Processing and Output
    while (inputFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        
        a = SideLengthTriangle(x1, y1, x2, y2);
        b = SideLengthTriangle(x2, y2, x3, y3);
        c = SideLengthTriangle(x3, y3, x1, y1);
        
        s = a + b + c;
        perCount++; // increment perimeter count
        
        area = AreaOfTriangle(a, b, c, s / 2); // calculates the triangle area
        
        if (perCount == 1) {
            maxP = minP = s;
        }

        if (area > 0) {
            count ++;
            
            sumP += s;
            sumArea += area;
            
            if (count == 1) {
                maxArea = minArea = area;
            }
            if (maxArea < area) {
                maxArea = area;
            }
            if (minArea > area) {
                minArea = area;
            }
            if (maxP < s) {
                maxP = s;
            }
            if (minP > s) {
                minP = s;
            }
        }
        
        
        // Output the vertices along with verdict of whether triangle or not
        cout << fixed << setprecision(2); // round to 2 decimal places
        cout << "(" << setw(6) << x1 << "," << setw(7) << y1 << ")"
             << "  (" << setw(6) << x2 << "," << setw(7) << y2 << ")"
             << "  (" << setw(6) << x3 << "," << setw(7) << y3 << ")    ";
        
        if (area > 0) {
            cout << "area =" << setw(9) << area << endl;
        }
        else {
            cout << "NOT A TRIANGLE" << endl;
        }
    }
    
    // print the report
    cout << "Maximum area = " << maxArea << endl;
    cout << "Minimum area = " << minArea << endl;
    cout << "Average area = " << sumArea / count << endl;
    inputFile.close();
    
    cout << endl << "*** Start Extra Credit ***" << endl << endl;

    cout << "Min Perimeter = " << minP << endl;
    cout << "Max Perimeter = " << maxP << endl;
    cout << "Average Perimeter = " << sumP / count << endl;

    cout << endl << "*** End Extra Credit ***" << endl;
    
    return 0;
}
