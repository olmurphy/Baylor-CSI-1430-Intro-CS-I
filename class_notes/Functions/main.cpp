//10/21/2019

#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "point.h" // function header from the header file



// NEVER PRINT IN A FUNCTION

void sayHello(int n);

using namespace std;
int main() {
    
    int x, y;
    x = 10;
    y = -5;
    
    display(x, -5);
    cout << distance(0, 0, 3, 4);
    
    return 0;
}

void sayHello(int n) {
    
    cout << "Hello World!" << endl;
}


// SOURCE FILE point.cpp
#include "point.h"

void display (int x, int y) {
    cout << "(" << x << "," << y << ")";
}

double distance (int x1, int y1, int x2, int y2) {
    return // the square root of the numbers
}



// Header File "point.h
#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <cmath>

using namespace std;

void display(int x, int y);
double distance (int x1, int y1, int x2, int y2); // names are not required in the prototype
    
#endif
    



/*
 10k functions
 
 
 
 
 */
// 10/22/2019



// header file "myFunctions.h" / pre-processor reads the #include
// precompiler marker
#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED
// prototype functions


int max(int, int);
int min(int, int);



#endif // MYFUNCTIONS_H_INCLUDED
// Everything in c++ is case sensitive !!!!!

// source file "myFunctions.cpp" // cpp gets compile NEVER #INCLUDE A CPP!
#include "myFunctions.h"

int max(int a, int b) {
    if (a < b) {
        a = b;
    }
    return a;
}

int min(int a, int b) {
    return a < b ? a : b; // ternary operator
}

// main

#include "myFunctions.h"

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << max(max(r + 1, c + 1), max (n - r, n - c)) << " "; // the expression is evaluated before it is passed in
        }
        cout << endl;
    }
    
    cout << max (10, 25) << endl;
}




// 10/28/2019

// slopt example

bool slope(int x1, int y1, int x2, int y2, double& m); // the '&' means pass the address of m (or meaning share the address) "pass by reference);
    // arrays are pass by reference
    // vectors are passed by value


int main() {
    
    double m;
    if (slope(0, 0, 1, 1, m)) {
        cout << "Slope = " << m << endl;
    }
    else {
        cout << "no slope" << endl;
    }
    
}


bool slope(int x1, int y1, int x2, int y2, double& m) { // this is the stub of the program
    bool has_slope = false;
    
    if (x1 != x2) {
        has_slope = true;
        m = static_cast<double>(y2 - y1)/(x2 - x1);
    }
    
    return has_slope;
}







// 11/06/2019

// Functions static

// "main.cpp"
#include <ostream>

void funct1(int&, const int&, ostream&); // compiler enforcement
// could be a large object where we don't want to copy bc it is so big

int funct2(int, int&, ostream&);


int main () {
    int n1, n2;
    
    n1 = 10;
    n2 = 5;
    funct1(n1, n2, cout);
    funct1(n1, n2, cout);
    funct1(n1, n2, cout);
    
    // static is a rare variable that should be used sparingly
    
}


// compiler enforcement
// could be a large object where we don't want to copy bc it is so big
// cout statement binds the function to the output stream
// Pass by reference shares
void funct1(int& a, const int& b, ostream& outStream) { // ostream is the parent of all output streams
    outStream << a << " ~ " << b << endl;
    a = b + 2;
    outStream << funct2(b, a, outStream);
    outStream << endl;
}


int funct2(int x, int& z, ostream& out) { // never copy a stream
    static int dog = 3; // only at compile time never again
    out << x << " ~ " << z << << " ~ " << dog << endl;
    dog += x;
    return x + z;
    
}


// cannot pass a function with literals












































































