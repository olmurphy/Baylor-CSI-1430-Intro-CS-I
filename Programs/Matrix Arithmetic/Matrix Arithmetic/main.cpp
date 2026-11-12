/*
 Author: Owen Murphy
 Assignment Title: Matrix Arithmetic
 Assignment Description: Write a program that multiplies
 Due Date: 11/01/2019
 Date Created: 10/29/2019
 Date Last Modified: 11/01/2019
 */

/*
 Data Abstraction:
    input file streams file1 and file2 to open the two files with the
        data in them regarding the 2 matrices
    strings fileName1 to store in first matrix file name, fileName2 to store
        in second matrix file name and operation to store the operation desired
        on the matrices
    integers r1, c1, r2, and c2 to store the dimensions of matrix 1 and matrix
        2 indicated by the number following the r and c
    integers r, c, and k for looping and indexing purposes
 Input:
    read in the first two file names for the matrices followed by the operation
        indicated
    read in the numbers from files into the two matrices
 Process:
    Depending on the operation indicated we are either going to add, multiply,
        or subtract the 2 matrices if the dimensions meet the requirements as
        subject to the operation.
 Output:
    Print the result of the operation to the screen automatic right aligned
        with the width of 5.
 Assumptions:
    It is assumed that the input in the two files are valid inputs
    It is assumed that that number of numbers contained in the files correspond
        to the correct dimensions of the file
    It is assumed that the input read from standard in is valid input.
 */

#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    // Data Abstraction
    ifstream file1, file2;
    string fileName1, fileName2;
    int r1, c1, r2, c2;
    int r, c, k;
    string operation;
    
    // Input
    cin >> fileName1 >> fileName2;
    cin >> operation;

    file1.open(fileName1);
    file2.open(fileName2);
        
    if (!file1) {
        cout << "Error: File " << fileName1 << " did not open." << endl;
        exit(1);
    }
    if (!file2) {
        cout << "Error: File " << fileName2 << " did not open." << endl;
        exit(1);
    }

    file1 >> r1 >> c1;
    file2 >> r2 >> c2;
    
    int matrix1[r1][c1];
    int matrix2[r2][c2];
    
    for (r = 0; r < r1; ++r) {
        for (c = 0; c < c1; ++c) {
            file1 >> matrix1[r][c];
        }
    }
    for (r = 0; r < r2; ++r) {
        for (c = 0; c < c2; ++c) {
            file2 >> matrix2[r][c];
        }
    }
    
    // Process
    if (operation == "multiply") {
        if (c1 == r2) {
            int result[r1][c2];
            
            // Process the multiplication of matrices
            for (r = 0; r < r1; ++r) {
                for (c = 0; c < c2; ++c) {
                    result[r][c] = 0;
                    
                    for (k = 0; k < c1; ++k) {
                        result[r][c] += matrix1[r][k] * matrix2[k][c];
                    }
                }
            }
            
            // Print the result matrix
            for (r = 0; r < r1; ++r) {
                for (c = 0; c < c2; ++c) {
                    cout << setw(5) << result[r][c];
                }
                cout << endl;
            }
            
        }
        else {
            cout << "Two matrices are not MULTIPLY comparable." << endl;
        }
    }
    
    if (operation == "subtract") {
        if (r1 == r2 && c1 == c2) {
            int result[r1][c1];
            
            // Process subtraction of matrices
            for (r = 0; r < r1; ++r) {
                for (c = 0; c < c1; ++c) {
                    result[r][c] = matrix1[r][c] - matrix2[r][c];
                }
            }
            
            // Print the result matrix
            for (r = 0; r < r1; ++r) {
                for (c = 0; c < c1; ++c) {
                    cout << setw(5) << result[r][c];
                }
                cout << endl;
            }
            
        }
        else {
            cout << "Two matrices are not SUBTRACT comparable." << endl;
        }
    }
    
    if (operation == "add") {
        if (r1 == r2 && c1 == c2) {
            int result[r1][c1];
            
            // Process addition of matrices
            for (c = 0; c < c1; ++c) {
                for (r = 0; r < r1; ++r) {
                    result[r][c] = matrix1[r][c] + matrix2[r][c];
                }
            }
            
            // Print the addition result matrx
            for (r = 0; r < r1; ++r) {
                for (c = 0; c < c1; ++c) {
                    cout << setw(5) << result[r][c];
                }
                cout << endl;
            }
            
        }
        else {
            cout << "Two matrices are not ADD comparable." << endl;
        }
    }
    
    file1.close();
    file2.close();
    
    return 0;
}
