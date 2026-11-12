/*
 Author: Owen Murphy
 Assignment Title: Closest Pair
 Assignment Description: Write a program that find the closes pair of points
    given an array of point objects;
 Due Date: 11/20/2019
 Date Created: 11/17/2019
 Date Last Modified: 11/20/2019
 */

#ifndef ClosestPair_h
#define ClosestPair_h

#include <cmath>
using namespace std;


struct Point{
     double x;
     double y;

     Point(double a = 0, double b = 0){
        x = a;
        y = b;
     }
};

struct Pair{
     int indexPointOne;
     int indexPointTwo;
};

//Function Prototype
/*
 Description:
    function that find the indices of the closest points in the array and
        returns a pair object with the two indices stored in the object data
 Return:
    returns a pair object
 Precondition:
    The array of object point and an integer indicating the size of array is
        passed in as parameters
    The values exist
 Postcondition:
    The values of the point object array and integer are unchanged
 */
Pair Closest_Pair( Point  P[ ], int n);


#endif /* ClosestPair_h */
