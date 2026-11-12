/*
 Author: Owen Murphy
 Assignment Title: Sqaure Matrix
 Assignment Description: Write a program that prints a square matrix that is a
    reflection of itself across a diagnol axis.
 Due Date: 10/21/2019
 Date Created: 10/19/2019
 Date Last Modified: 10/21/2019
 */

/*
 Data Abstraction:
    integer num to store the dimensions of the sqaure matrix
    integers r and c for looping purposes
 Input:
    read in the number from standard input that tells the dimensions of the
        square matrix
 Process:
    delcare a square matrix of the dimension by the number read
        and process values to create a reflection of the
        matrix across the diagnol axis
    Store each numcher
 Output:
    Print the matrix the to screen
 Assumptions:
    It is assumed that the input is a valid integer of positive numbers only
    It is assumed that the input read ends with a 0.
    
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <ios>
#include <iomanip>
using namespace std;

int main() {
    
    int N;
    int r, c;
    
    cin >> N;
    
    while (N > 0) {
        // declare the square matrix array of size num;
        int a[N][N];
    
        
        // input values to create the reflective matrix along the diagnol axis
        for (r = 0; r < N; ++r) {
            for (c = 0; c < N; ++c) {
                a[r][c] = min (min (r + 1, c + 1), min(N - r, N - c));
            }
        }
        
        // Print out the square matrix followed by newline
        for (r = 0; r < N; ++r) {
            for (c = 0; c < N; ++c) {
                cout << setw(3) << right << a[r][c] << " ";
            }
            cout << endl;
        }
        
        cout << endl;
        
        // prompt for another number
        cin >> N;
     
    }
    return 0;
}
