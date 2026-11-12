/*
 Author: Owen Murphy
 Assignment Title: Awesome Sqaure
 Assignment Description: Write a program // FIXME: add description
 Due Date: 09/27/2019
 Date Created: 09/24/2019
 Date Last Modified: 09/24/2019 // FIXME: fix the date
 */

/*
 Data Abstraction:
    variables
 Input:
    read a number
 Process:
    do stuff with number
 Output:
    output yes
 Assumptions:
    it is assumed 
 */
// FIXME: Update the documentation header

#include <iostream>
using namespace std;

int main() {
    int numCases, numDim, value, targetSum;
    int sum = 0;
    bool flag = true;
    
    cin >> numCases;
    
    for (int i = 1; i <= numCases; i++) {
        cin >> numDim;
        flag = true;
        for (int row = 1; row <= numDim; row++) {
            sum = 0;
            for (int col = 1; col <= numDim; col++) {
                cin >> value;
                sum += value;
            }
            if (row == 1) {
                targetSum = sum;
            }
            if (sum != targetSum) {
                flag = false;
            }
        }
        if (flag) {
            cout << "Awesome" << endl;
        }
        else {
            cout << "Not Awesome" << endl;
        }
    }
    
    
    
    
    return 0;
}
