/*
 Author: Owen Murphy
 Assignment Title: Magic Square
 Assignment Description: Write a program that checks if the square matrix
    read in from standard in is a magic square or not
 Due Date: 10/30/2019
 Date Created: 10/25/2019
 Date Last Modified: 10/30/2019
 */

/*
 Data Abstraction:
    integer numCases to store number of cases
    integer numer to read in the numbers from standard in
    integer target sum to store the that all rows, columns and diagnols should
        evaluate to
    integer r and c for looping purposes
    boolean isMagic to store true if magic and else isMagis is false
    integer sum to store the sum of the rows and columns and the other two
        diagnol sum integers to store the sum of the diagnols
 Input:
    read in number of cases, read in the dimensions of the square matrix, and
        read in the integers into the sqaure matrix
 Process:
    iterate through the matrix and check to see if the sum of each row, column,
        and diagnol evaulate to the correct sum. If one condition is not equal
        to the target sum then set isMagic to false and stop processing
 Output:
    Output magic square if isMagic is true else not magic square if false
 Assumptions:
    It is assumed that all the input is valid input.
    It is assumed that the correct number of test cases exist
    It is assumed that all the integers in the square matrix are unique
    
 */

#include <iostream>
#include <cmath>
#include <ios>
#include <iomanip>
using namespace std;

int main () {
    
    int numCases;
    int n, r, c, sum, sumFirstDiag, sumSecondDiag;
    int targetSum;
    bool isMagic;

    // Input
    cin >> numCases;
    
    for (int i = 0; i < numCases; ++i) {
        isMagic = true;
        cin >> n;
        targetSum = (n * (pow(n, 2) + 1)) / 2;
        
        // declare the square matrix array
        int a[n][n];
        
        // Read in numbers for square matrix
        for (r = 0; r < n; ++r) {
            for (c = 0; c < n; c++) {
                cin >> a[r][c];
            }
        }
        
        // Process
        // Check the numbers in each row to validate whether they equal the
        // target sum
        for (r = 0; r < n && isMagic; ++r) {
            sum = 0;
            for (c = 0; c < n; ++c) {
                sum += a[r][c];
            }
            if (sum != targetSum) {
                isMagic = false;
            }
        }
        // Check numbers in each column to validate whether they equal the
        // target sum
        for (c = 0; c < n && isMagic; ++c) {
            sum = 0;
            for (r = 0; r < n; ++r) {
                sum += a[r][c];
            }
            if (sum != targetSum) {
                isMagic = false;
            }
        }
        // Check numbers in diagnol to validate whether they equal the target
        // sum
        sumFirstDiag = 0;
        sumSecondDiag = 0;
        for (r = 0; r < n && isMagic; ++r) {
            for (c = 0; c < n; ++c) {
                if (r == c) {
                    sumFirstDiag += a[r][c];
                }
                if (r == (n - c - 1)) {
                    sumSecondDiag += a[r][c];
                }
            }
        }
        if (sumFirstDiag!= targetSum || sumSecondDiag != targetSum) {
            isMagic = false;
        }
        
        // Out put whether it is a magic square or not
        if (isMagic) {
            cout << "Magic Square" << endl;
        }
        else {
            cout << "Not Magic Square" << endl;
        }
    }
    return 0;
}
