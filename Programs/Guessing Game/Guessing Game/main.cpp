/*
 Author: Owen Murphy
 Assignment Title: Guessing Game
 Assignment Description: Write a program that generates a random number and
    has the user guess the number until they get the right answer
 Due Date: 09/25/2019
 Date Created: 09/24/2019
 Date Last Modified: 09/25/2019
 */

/*
 Data Abstraction:
    declare variables min, max, range, randNum, count, and guess
 Input:
    Read two integers and then ask for user to guess the random number that was
    generated
 Process:
    Count the number of guesses, produce a range and a random number
 Output:
    Output too high or too low if the guess is higher than or lower than the
    random number. If the guess is equal to the randNum then print correct and
    display the number of attempts it took to guess the number
 Assumptions:
    It is assumed the user will be enter valid integers for the range
    It is assumed the user will type integer values for the guess
    It is assuemd the user will not type anything but integers for the range
    and the input
 */


#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    
    // Data Abstraction
    int min, max, range, randNum, count, guess;
    srand(static_cast<unsigned int>(time(NULL)));
    
    // Input
    cout << "Please enter 2 integers: ";
    cin >> min >> max;
    cout << min << " " << max << endl; // Echo print
    
    // Process and Output
    count = 0;
    if (min > max) {
        swap(min, max);
    }
    range = abs(max - min) + 1;
    randNum = rand() % range + min;
    cout << "I'm and thinking of a number between " << min << " and " <<
    max << "." << endl;
    
    do {
        cout << "Enter guess: ";
        cin >> guess;
        count++;
        if (guess < randNum) {
            cout << guess << " - Too Low" << endl;
        }
        if (guess > randNum) {
            cout << guess << " - Too High" << endl;
        }
        
    } while (guess != randNum);
    
    // Output
    cout << guess << endl;
    cout << "Correct, it took you " << count << " tries to guess my number." <<
    endl;
    
    
    return 0;
}
