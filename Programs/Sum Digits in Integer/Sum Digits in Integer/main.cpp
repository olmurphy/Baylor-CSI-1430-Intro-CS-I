/*
 Author: Owen Murphy
 Assignment Title: Sume the Digits in an Integer
 Assignment Description: Write a program that sums the digits in an integer
 Due Date: 09/11/2019
 Date Created: 09/09/2019
 Date Last Modified: 09/11/2019
*/

/*
 Data Abstraction:
            Output file stream is opened
            4 variables, sum, n product, and ave, are declared and assigned
            to a value
 Input:
            Program reads input of the integer and stores in the in the
            variable n
 Process:
            The sum of the three digits is caclculated using a series of
            calculations
 Output:
            After the processing the calculations, the result is then outputted
            to the screen
 Assumptions:
            It is assuemd that the user only prints a positive integer
            containing three significant digits
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
int main() {
    
    int sum, n;
    
    cout << "Enter an integer between 0 and 999: " << endl;
    
    // Input
    cin >> n;
    cout << n;
    
    sum = 0;
    
    // Process
    sum += n % 10;
    sum += ((n / 10) % 10);
    sum += ((n / 10) / 10);
    
    // Output
    cout << "The sum of the digits is " << sum << "." << endl;
    
    cout << "*** Start Extra Credit ***" << endl;
    
    // Variable Declaration
    int product;
    double ave;
    
    // Variable Declaration
    product = 0;
    ave = 0;
    
    // Calculate Product and Average of digits
    product += (n % 10);
    product *= ((n / 10) % 10);
    product *= ((n / 10) / 10);
    
    
    ave = (sum / 3.0);
    
    // <Extra Credit Output>
    cout << "Product = " << product << endl;
    
    cout <<fixed << setprecision(1);
    cout << "Average = " << ave << endl;
    
    
    
    
    cout << "*** End Extra Credit ***" << endl;
    
    return 0;
}
