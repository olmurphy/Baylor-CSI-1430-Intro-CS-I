/*
 Author: Owen Murphy
 Assignment Title: Letter Grade
 Assignment Description: write a program that calculates the average of 5
    test scores
 Due Date: 09/20/2019
 Date Created: 09/20/2019
 Date Last Modified: 09/20/2019
 */

/*
 Data Abstraction:
    declare 5 doubles as test grades, score as a double, sum for more
    compact process, and boolean gamepass to run if applicable
 Input:
    Prompt for 5 doubles and read the input and store in a double for
    later calculations for the processor to process.
 Process:
    Calculate the average of the five test scores
    output average and grade when game equals true
 Output:
    Report the data entered by user and report the average rounded to
    two decimal places
 Assumptions:
    It is assumed that the user got above a 0 and below a 100, if not then
    print error
 */


#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

int main() {
    
    // Data abstraction
    double n1, n2, n3, n4, n5, sum, score = 0;
    char grade = 'A';
    bool game = true;
    
    // Input
    cout << "Please enter 5 test scores: " << endl;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    
    
    // Process
    if (n1 < 0.0 || n1 > 100.0 || n2 < 0.0 || n2 > 100.0 || n3 < 0.0 ||
        n3 > 100.0 || n4 < 0.0 || n4 > 100.0 || n5 < 0.0 || n5 > 100.0) {
        game = false;
    }
    else {
        sum = n1 + n2 + n3 + n4 + n5;
        score = sum / 5.0;
    }
    
    if (game) {
        if (score <= 59.49) {
            grade = 'F';
        }
        else if (score >= 59.50 && score <= 69.49) {
            grade = 'D';
        }
        else if (score >= 69.50 && score <= 79.49) {
            grade = 'C';
        }
        else if (score >= 79.50 && score <= 89.49) {
            grade = 'B';
        }
        else {
            grade = 'A';
        }
    }
    else {
        // false block
    }
    
    // Output
    cout << fixed << setprecision(2);
    if (game) {
        cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl << n5;
        cout << endl;
        cout << "Average = " << score << endl;
        cout << "Grade = " << grade << endl;
    }
    else {
        cout << "Error: Bad Data" << endl;
    }

    return 0;
}
