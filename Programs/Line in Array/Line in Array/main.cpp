/*
 Author: Owen Murphy
 Assignment Title: Line in Array
 Assignment Description: Write a program that reach number, stores them in
    an array does does the operation specified by input on the specified
    line
 Due Date: 10/23/2019
 Date Created: 10/21/2019
 Date Last Modified: 10/23/2019
 */

/*
 Data Abstraction:
    variable char operation to store the desired arithmatic operation
    integer row to store the indicated line to perform operation on\
    integer sum to keep track of the summed row
    array of type double of size 12 row by 12 columnsd
    double average to store the average of the numbers
 Input:
    read in the specified row to perform operation on
    read in the character to determine sum or average arithmetic operation
 Process:
    store each number read from standard in to the sqaure matrix of size 12
        by 12
    sum the number in the row and calculate the average
 Output:
    print the sum or average depending on what the character specifies
 Assumptions:
    It is assumed that the input is in the order as stated on the assignment
    It is assumed that all input is valid input
 */



#include <iostream>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 12;
int main() {
    
    // Data Abstraction
    char operation;
    int row;
    double sum = 0;
    double a[ARRAY_SIZE][ARRAY_SIZE]; // sqaure matrix to store values
    double average;
    
    // Input
    cin >> row;
    cin >> operation;
    
    for (int r = 0; r < ARRAY_SIZE; ++r) {
        for (int c = 0; c < ARRAY_SIZE; ++c) {
            cin >> a[r][c];
        }
    }
    
    // Process
    for (int c = 0; c < ARRAY_SIZE; ++c) {
        sum += a[row][c];
    }
    average = sum / ARRAY_SIZE;
    
    // Output
    cout << fixed << setprecision(1);
    switch(operation) {
        case 'S':
            cout << sum << endl;
            break;
        case 'M':
            cout << average << endl;
    }
    
    return 0;
}
