/*
 Author: Owen Murphy
 Assignment Title: Pascal's Triangle
 Assignment Description: Write a function that prints out the Pascal's triangle
    using the combination function and factorial function based on the row and
    column
 Due Date: 11/08/2019
 Date Created: 11/05/2019
 Date Last Modified: 11/08/2019
 */

/*
 Data Abstraction:
    integers r and c to loop through the pascal's triangle
    integer n to store the number of lines to print
 Input:
    read in number of lines for pascal
 Process:
    for Pascal's triangle, we call the combination function from previous
        programming assignment using the row as the number of elements and the
        column as the number taken at a time.
 Output:
    From calling the combination function, we print the result to the screen in
        the desired output format as specified in the assignment
 Assumptions:
    It is assumed that the data from input is valid input
 */

#include <iostream>
#include <iomanip> // setw(), left (justified)
#include <ios>  // left (justified)
//#include "myFunctions.h" // combination and factorial function are called
using namespace std;

double factorial(int n);

double combination(int M, int N);

int main() {
    
    // Data Abstraction
    int r, c, n;
    
    // User Input
    cout << "Please Enter The Number of Rows: ";
    cin >> n;
    cout << n << endl;
    
    // Data Processing & Output
    for (r = 0; r < n; ++r) {
        
        for (int i = 0; i < (n - r) * 4; ++i) {
            cout << ' ';
        }
            
        for (c = 0; c <= r; ++c) {
            cout << left << setw(8) << combination(r, c);
        }
        cout << endl;
    }
    
    cout << endl << "*** Start Extra Credit ***" << endl << endl;

    // <Extra Credit Output>
    for (r = n - 1; r >= 0; --r) {
            
        for (int i = 0; i < (n - r) * 4; ++i) {
                cout << ' ';
        }
        
        for (c = 0; c <= r; ++c) {
            cout << left << setw(8) << combination(r, c);
        }
        cout << endl;
            
    }
    cout << endl<< "*** End Extra Credit ***" << endl << endl;
    
return 0;
}

double combination(int M, int N) {
    assert(M >= N);     // checking to make sure there is not a negative
                        // factorial
    return factorial(M) / (factorial(M - N) * factorial(N));
}

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
