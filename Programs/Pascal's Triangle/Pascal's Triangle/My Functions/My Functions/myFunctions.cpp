/*
Author: Owen Murphy
Assignment Title: My Functions
Assignment Description: Write Functions that can be tested and used
Due Date: 11/06/2019
Date Created: 11/02/2019
Date Last Modified: 11/06/2019
*/

#include "myFunctions.h"

int max(int a, int b) {
    
    return a < b ? b : a; // Return b if it is greater, else return a
}

double max(double a, double b) {
    
    return (a > b) ? a : b; // return the greater of the two doubles
}

int max(int m[], int n) {
    int largestInteger;
    int i;
    
    largestInteger = m[0]; // Setting largest integer equal to first value
    for (i = 1; i < n; ++i) { // loop and find the max value
        if (largestInteger < m[i]) {
            largestInteger = m[i];
        }
    }
    
    return largestInteger;
}

double max(double m[], int n) {
    double largestVal;
    int i;
    
    largestVal = m[0]; // Setting largest val = to first value in array
    for (i = 1; i < n; ++i) { // loop and find the max value
        if(largestVal < m[i]) {
            largestVal = m[i];
        }
    }
    
    return largestVal;
}

int min (int a, int b) {
    
    return a > b ? b : a; // return b is if is smaller, else return a
}

double min(double a, double b) {
    
    return a > b ? b : a; // return b if it is smaller, else return a
}

int min(int m[], int n) {
    int smallestVal;
    int i;
    
    smallestVal = m[0]; // assign smallestVal to the first value
    for (i = 1; i < n; ++i) { // loop through and find the smallest value
        if(smallestVal > m[i]) {
            smallestVal = m[i];
        }
    }
    
    return smallestVal;
}

double min(double m[], int n) {
    double smallestVal;
    int i;
    
    smallestVal = m[0]; // assigned smallestVale to first value
    for (i = 1; i < n; ++i) { // loop to find the smallest value
        if(smallestVal > m[i]) {
            smallestVal = m[i];
        }
    }
    return smallestVal;
}

int absoluteValue(int a) {
    
    return (a < 0) ? a * (-1) : a;  // if a is negative make it positive, else
}                                   // return a

double absoluteValue(double a) {
    return (a < 0) ? a * (-1.0) : a; // if a is negative make it postive and
}                                    // return a, else return a

// Factorials should always be 1 or greater unless we apply Eurler's gamma
// function
double factorial(int n) {
    assert(n >= 0); // check to make sure no negative factorial
    double value = 1;
    double pValue;

    while(n > 0) {
        pValue = value;
        value *= n;
        n--;
        assert(value >= pValue || value == 1); // check to make sure overlaod
                                               // is not happening
        assert(value > 0); // check to make sure the value is not negative
    }                      // a negative indicates overflow
    
    return value;
}

double combination(int M, int N) {
    assert(M >= N);     // checking to make sure there is not a negative
                        // factorial
    return factorial(M) / (factorial(M - N) * factorial(N));
}

double permutation(int M, int N) {
    assert(M >= N); // check to make sure no negative factorial
    
    return factorial(M) / factorial(M - N);
}
