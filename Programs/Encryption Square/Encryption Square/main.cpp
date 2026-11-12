/*
 Author: Owen Murphy
 Assignment Title: Encryption Square
 Assignment Description: Write a program that encodes a message using the
    expanding square matrix method
 Due Date: 10/28/2019
 Date Created: 10/22/2019
 Date Last Modified: 10/28/2019
 */

/*
 Data Abstraction:
    integers n to store size of string, side to store the dimesnions of the
        square matrix
    integers r, c, and i to store indexing purposes
    integer count to store index for looping through the message
    string message to store the decoded message
    integer currDir to store the 0-3 for direction purposes
    integer steps to keep track of the steps taken in each direction
 Input:
    read in the message from standard input
 Process:
    store the input string into a square matrix and decode the matrix based
        using the expanding square matrix method of encoding a message
    We will decode the matrix by looping throught the square matrix
        decrementing or incrementing the row or column depending on the case
        of the current direciton. Current direction is initialized to 0 - right
 Output:
    output the encoded message
 Assumptions:
    It is assumed that the input is on one line
    It is assumed that the input is valid input
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    
    // Data abstraction
    int n;
    int side;
    int r, c, i;
    int count;
    string message;
    int steps;
    int currDir = 0;
    /*
    0 indicates the direction for current direction (i.e. right)
    for mapping through the square matrix, 1 indicates down, 2 indicates left,
    and 3 indicates up.
    */
     
    // Input
    getline(cin, message);
    n = static_cast<int>(message.size());
    
    side = 1;
    while(pow(side, 2) < n) {
        side++;
        if (side % 2 == 0) {
            side++;
        }
    }
    
    // Declare the smallest odd square matrix
    char messageDecode[side][side];
    
//  read in the message into the smallest square matrix
    i = 0;
    for (r = 0; r < side; ++r) {
        for (c = 0; c < side; ++c) {
            if (i < n) {
                messageDecode[r][c] = message.at(i);
                ++i;
            }
            else {
                messageDecode[r][c] = '*';
            }
        }
    }
    
    // start the square matrix at the beginning and spiral outwards to encrypt
    r = side/2;
    c = side/2;
    count = 0;
    steps = 1;
    
    while (count < pow(side, 2)) {
        for (int i = 0; i < steps; ++i) {
            cout << messageDecode[r][c];
            count++;
            switch(currDir) {
                case 0: c++;
                        break;
                    
                case 1: r++;
                        break;
                    
                case 2: c--;
                        break;
                    
                case 3: r--;
                        break;
            }
        }
        currDir++;
        currDir %= 4;
        
        if (r == c) {
            steps++;
        }
    }
    
    cout << endl;
    
    return 0;
}
