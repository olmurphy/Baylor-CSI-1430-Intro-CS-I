/*
 Author: Owen Murphy
 Assignment title: URI: R + L = J
 Assignment Description: Write a program that tests cases and find the missing
    value in the algebra formula
 Due Date: 10/14/2019
 Date Created: 10/10/2019
 Date Last Modified: 10/14/2019
 */

/*
 Data Abstraction:
    String declaration to read in the line
    input string stream to put line into a buffer
    integers R, L, and J to store the values of the integers
    more strings to read lines specific lines into 3 strings for later purpose\
    input string stream to read in the number
 Input:
    read in a line and also read into a string stream (input)
 Process:
    Read in each expression excludign the arithmetic expressions
    Once the missing variable is found blow the char in to a char variable
        and switch on the char finding the value of the missing variable
 Output:
    print the missing value to the screen and end with new line
 Assumptions:
    It is assumed that the string contains no spaces
    It is assumed that the test cases contain valid integers
    It is assumed that the format of the string does not change
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <ios>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {

    string str1, str2, str3;
    stringstream intStream;
    double r, l, j;
    char unknown;
    
    // Input
    while (getline (cin, str1, '+')) {
        getline (cin, str2, '=');
        getline (cin, str3);
        cout << str1 << " " << str2 << " " << str3 << endl;
        intStream.clear();
        
        
        if (isdigit(str1.at(0)) || str1.at(0) == '-') {
            intStream.clear();
            intStream.str(str1);
            intStream >> r;
            cout << "r: " << r << endl;
        }
        else {
            unknown = 'r';
        }
        
        if (isdigit(str2.at(0)) || str2.at(0) == '-') {
            intStream.clear();
            intStream.str(str2);
            intStream >> l;
            cout << "l: " << l << endl;
        }
        else {
            unknown = 'l';
        }
        
        if (isdigit(str3.at(0)) || str3.at(0) == '-') {
            intStream.clear();
            intStream.str(str3);
            intStream >> j;
            cout << "j: " << j << endl;
        }
        else {
            unknown = 'j';
        }
        
        switch (unknown) {
            case 'r':
                r = j - l;
                cout << "r: " << r << endl;
                break;
            case 'l':
                l = j - r;
                cout << "l: " << l << endl;
                break;
            default:
                j = r + l;
                cout << "j: " << j << endl;
                break;
        }
    
    }
    
    return 0;
}
