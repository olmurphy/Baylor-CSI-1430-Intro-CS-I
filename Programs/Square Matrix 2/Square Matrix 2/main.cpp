/*
 Author: Owen Murphy
 Assignment Title: Square Matrix 2
 Assignment Description: Write a program that prints a square matrix
    of powers with basing being 2
 Due Date: 11/04/2019
 0Date Created: 11/01/2019
 Date Last Modified: 11/04/2019
 */

/*
 Data Abstraction:
    integers n to store the input, r and c for looping purposes, width store
        store the largest number of digits in the biggest integer and
        biggestNum to store the biggest number
 Input:
    Read in the number indicating the size of the square matrix
 Process:
    Find the biggest integer of the square matrix with base of to and set the
        number of digits in the integer plus one in the width integer variable
 Output:
    Print the matrix of base to the the power of row plus column to the screen
 Assumptions:
    It is assumed the input read ends with a zero
    It is assumed the input is valid integers
 */

#include <iostream>
#include <iomanip> // fixed, setprecision()
#include <cmath> // pow()
using namespace std;

int main() {
    
    // Data Abstraction
    int n, r, c, width;
    int biggestNum;
    
    // User Input
    cin >> n;
    
    // DataProcessing & Output
    // Input ends with zero
    while(n > 0) {
        
        // Find the number of digits in biggest integer plus one and set
        // set that to the variable width for output formatting
        width = 0;
        biggestNum = pow(2, n + n - 2);
        while (biggestNum) {
            biggestNum /= 10;
            width++;
        }
        
        // format the output
        cout << fixed << setprecision(0);
        
        // loop and output the "matrix" of the base to the power of c + r;
        for (r = 0; r < n; ++r) {
            for (c = 0; c < n; ++c) {
                cout << setw(width + 1) << pow(2, c + r);
            }
            cout << endl;
        }
        cout << endl;
        cin >> n;
    }
    
    return 0;
}
