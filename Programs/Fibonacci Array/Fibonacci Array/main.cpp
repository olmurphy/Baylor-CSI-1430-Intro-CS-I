/*
 Author: Owen Murphy
 Assignment Title: Fibonacci Array
 Assignment Description: write a program that ouputs the fibonacci number
    of the given index
 Due Date: 10/18/2019
 Date Created: 10/14/2019
 Date Last Modified: 10/18/2019
 */

/*
 Data Abstraction:
    constant integer for number of elements in fibonacci array
    unsigned long int fibonacci array to store the fibonacci numbers
    integers numCase to store number of test cases and caseNum to read the
        number
 Input:
    read in the number of test cases and the number at the case
 Process:
    loop through the un the reading of the numbers reaches the end of the
        number of test cases
 Output:
    print out the value of the index read that corresponds to the index value
        in the fibonacci array
 Assumptions:
    It is assumed that the input is integers only
    Is is assumed that the input read number is within the range of 0 to 95
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int NUMBER_IN_FIB = 96;
int main() {
    
    // Data Abstraction
    unsigned long int fib[NUMBER_IN_FIB];
    int numCase, caseNum;
    int i;
    
    // Populate the array
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < NUMBER_IN_FIB; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        
    }
    
    // read in number of test cases
    cin >> numCase;
    
    // loop through each number and print corresponding fibonacci number
    for (i = 1; i <= numCase; ++i) {
        cin >> caseNum;
        cout << "Case " << i << ": Fib(" << caseNum << ") = " << fib[caseNum];
        cout << endl;
    }
    
    return 0;
}
    
    
    
