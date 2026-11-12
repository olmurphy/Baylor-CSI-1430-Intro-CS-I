/*
 Author: Owen Murphy
 Assignment Title: My Functions
 Assignment Description:
 Due Date: 11/06/2019
 Date Created: 11/02/2019
 Date Last Modified: 11/06/2019
 */

/*
 Data Abstraction:
 Input:
 Process:
 Output:
 Assumptions:
 */

#include <iostream>
#include "myFunctions.h"
using namespace std;

int main() {
    
    // Data Abstraction
    
    // User Input
    
    // Data Processing & Output
    
    int x = 2, y = -5;
    cout << max(x, y) << endl;
    
    double a = 20.0, b = 3.5;
    cout << max(a, b) << endl;
    
    int c[8] = {5, 34, 53, 56, 2345, 15, 15, 26};
    cout << max(c, 8) << endl;
    
    double ab[8] = {5.8, 34.4, 53.2, 56.3, -2345.3, 15.3, 15.3, 26.3};
    cout << max(ab, 8) << endl;
    
    cout << min(x, y) << endl;
    
    cout << min(a, b) << endl;
    
    cout << min(c, 8) << endl;
    
    cout << min(ab, 8) << endl;
    
    cout << absoluteValue(2) << endl;
    
    cout << absoluteValue(0) << endl;
    
    cout << factorial(3) << endl;
    
    cout << combination(2, 1) << endl;
    
    cout << combination(8, 2) << endl;
    
    cout << permutation(5, 3) << endl;
    
    cout << permutation(8, 2) << endl;
    
    
    cout << endl << endl;
    
        cout << combination(8, 2) << endl;
        cout << combination(8, 2) << endl;
        cout << combination(8, 2) << endl;
        cout << combination(8, 2) << endl;
        cout << combination(8, 2) << endl;
        cout << combination(8, 2) << endl;
        cout << combination(8, 2) << endl;
        cout << combination(8, 2) << endl;
    
    
    return 0;
}
