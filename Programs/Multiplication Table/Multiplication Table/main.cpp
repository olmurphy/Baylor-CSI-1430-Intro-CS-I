/*
 Author: Owen Murphy
 Assignment Title: Multiplication Table
 Assignment Description: Write a program that prints a multiplication table
    from the integers ragnes of inputs
 Due Date: 09/30/2019
 Date Created: 09/30/2019
 Date Last Modified: 09/30/2019
 */

/*
 Data Abstraction:
    Integers deltaRow and deltaCol are declared and initialized for
        incrementing or decrementing
    Integers R1, R1, C1 and C2 are declared for the ranges for the
        multiplication table
 Input:
    Read in input of row and columns
 Process:
    Multiply each row number the the individual column number and move to next
        row. Dow the same until you reach the end of the rows (inclusively)
 Output:
    Print the multiplication table to the screen
 Assumptions:
    It is assumed the user will enter 4 integer variables
    It is assumed the user only wants a multiplication chart from the ranges
        of the rows and columns
 */

#include <iostream>
#include <cmath>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <ios>
#include <ostream>

using namespace std;

const int WIDTH = 6;
int main() {
    
    int deltaRow = 1;
    int deltaCol = 1;
    int R1, R2, C1, C2;
    
    cout << "Please Enter Four Integers R1 R2 C1 C2: ";
    cin >> R1 >> R2 >> C1 >> C2;
    cout << R1 << " " << R2 << " " << C1 << " " << C2 << endl;
    
    if (R1 > R2) {
        deltaRow = -1;
    }
    if (C1 > C2) {
        deltaCol = -1;
    }
    
    cout << "   ";
    for (int col = C1; col != (C2 + deltaCol); col += deltaCol) {
        cout << setw(WIDTH) << col;
    }
    cout << endl;
    for (int row = R1; row != (R2 + deltaRow); row += deltaRow) {
        for (int i = 0; i != ((C2 - C1) + (deltaCol * 2)); i += deltaCol) {
            cout << "-----|";
        }
        cout << endl;
        cout << left << setw(8) << row;
        for (int col = C1; col != (C2 + deltaCol); col += deltaCol) {
            cout << setw(WIDTH) << row * col;
        }
        cout << endl;
        
    }
    for (int i = 0; i != ((C2 - C1) + (deltaCol * 2)); i += deltaCol) {
        cout << "-----|";
    }
    cout << "\n" << "\n";
    
    
    
    
    return 0;
}
