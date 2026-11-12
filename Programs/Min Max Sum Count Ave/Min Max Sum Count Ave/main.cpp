/*
 Author: Owen Murphy
 Assignment Title: Min Max Sum Count Average
 Assignment Description: Write a program that takes in inputs while input is
    not equal to stop value and process the set of instructions to copmute
    statistical data
 Due Date: 09/23/2019
 Date Created: 09/21/2019
 Date Last Modified: 09/23/2019
 
 */

/*
 Data Abstraction:
    Declare integers num, sum, count, min, and max. Declare double average to
    find average of the numbers
 Input:
    take in integers until input is equal to stop value to be used for later
    instructions
 Process:
    take in inputs until input is equal to stop value and process the set of
    instructions to calculate the sum, count, min, max, and average while the
    input value is not equal to the stop value
 Output:
    print the sum, count, average, min, and max to the screen
 Assumptions:
    it is assumed that the user only wants those five statisctial data to be
    shown onthe screen
    it is assumed that the user will want to type in at least one number before
    typing the stop value
 */

#include <cmath>
#include <cctype>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

const int STOP_VALUE = -999;
int main() {
    
    // Data Abstraction
    int num, sum = 0, count = 0, min, max;
    double ave = 0;
    
    
    // Input
    // Process
    do {
        cin >> num;
        if(num != STOP_VALUE) {
            count ++;
            sum += num;
            if (count == 1) {
                min = max = num;
            }
            if(min > num) {
                min = num;
            }
            if(max < num) {
                max = num;
            }
            ave = static_cast<double>(sum) / count;
        }
    } while (num != STOP_VALUE);
    
    
    
    // Output
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    cout << "Sum = " << sum << endl;
    cout << "Count = " << count << endl;
    cout << fixed << setprecision(3);
    cout << "Average = " << ave << endl;
    
    cout << "*** Start Extra Credit ***" << endl;
    
    int range;
    double midRange;
    
    range = max - min;
    midRange = (min + max) / 2.0;
    
    
    // <Extra Credit Output>
    cout << "Range = " << range << endl;
    cout << fixed << setprecision(3);
    cout << "Midrange = " << midRange << endl;

    cout << "*** End Extra Credit ***" << endl;
    
    return 0;
}


/* 25
75
84
92
88
59
88
52
79
48
11
83
12
92
77
92
80
52
10
53
32
-999
*/
