/*
 Author: Owen Murphy
 Assignment Title: Arithmetic Mean, Geometric Mean, Harmonic Mean, & Standard
 Deviation
 Assignment Description: Write a program that calculates the means and
 standard deviation of the five intergers inputed
 Due Date: 09/13/2019
 Date Created: 09/11/2019
 Date Last Modified: 09/11/2019
 */

/*
 Data Abstraction:
    Output file stream is opened
    17 variables are declared, 12 for the purpose of calculation and storing
    results
 Input:
    Program reads the input of five integers and stores them in the int
    variable n1, n2, n3, n4, n5
 Process:
    The Arithmetic mean is calculated taking the sum of all numbers and
    dividing by the amount of numbers added
    The Geometric Mean is calculated by taking the product of the 5 integers and
    raising to the power of 1/n, n = # of numbers being multiplied
    The Harmonic Mean is calculated by summing the reciprocals of each integer
    inputs and dividing the result into the 5.0
 Output:
    Print the original 5 integers and then print the results of the calculated
    means and STDEV
 Assumptions:
    It is assumed that the person inputs only five integers
 */


#include <cmath>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int n1, n2, n3, n4, n5;
    double sum, geoMean, sumRat, harMean, arMean, powSum, stdev, pow1, pow2,
    pow3, pow4, pow5, product;
    
    cout << "Enter five numbers:" << endl;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl;
    cout << n5 << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    
    // Assign variables to 0
    sum = 0;
    geoMean = 0;
    sumRat = 0;
    harMean = 0;
    arMean = 0;
    powSum = 0;
    stdev = 0;
    pow1 = 0;
    pow2 = 0;
    pow3 = 0;
    pow4 = 0;
    pow5 = 0;
    
    // Arithmetic Mean Calculation
    sum = n1 + n2 + n3 + n4 + n5;
    arMean = (sum / 5.0);
    
    // Geometric Mean Calculation
    product = (static_cast<long double>(n1) * n2 * n3 * n4 * n5);
    geoMean = pow(product, 0.2);
    

    // Harmonic Mean Calculation
    sumRat = ((1.0 / n1) + (1.0 / n2) + (1.0 / n3) + (1.0 / n4) + (1.0 / n5));
    harMean = (5.0 / sumRat);
    
    
    // STDEV Calculation
    pow1 = pow((n1 - arMean), 2);
    pow2 = pow((n2 - arMean), 2);
    pow3 = pow((n3 - arMean), 2);
    pow4 = pow((n4 - arMean), 2);
    pow5 = pow((n5 - arMean), 2);
    powSum = pow1 + pow2 + pow3 + pow4 + pow5;
    stdev = sqrt(powSum / 5.0);
    
    // Print the 5 integers
    
    cout << "Result: \n" << endl;
    cout << "Data: \n";
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl;
    cout << n5 << endl;
    cout << endl;
    
    // Output the results of the means and STDEV
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean    = " << arMean << endl;
    cout << "Geometric  Mean    = " << geoMean << endl;
    cout << "Harmonic   Mean    = " << harMean << endl;
    cout << "Standard Deviation = \n" << stdev << endl;
    
    
    cout << "*** Start Extra Credit ***" << endl;
    
    // Root Mean Square calculation
    
    double squareAve = 0, rootMeanSquare = 0;
    
    squareAve = (pow(n1, 2 ) + pow(n2, 2) + pow(n3, 2) + pow(n4, 2) + pow(n5, 2)
                 );
    rootMeanSquare = sqrt(squareAve / 5.0);
    
    // 20 % Winsoriezed Mean (sort 5 integers using bubble sort)
    
    double winsMean;
    
    if (n1 > n2) {
        swap (n1, n5);
    }
    if (n1 > n3) {
        swap (n1, n3);
    }
    if (n1 > n4) {
        swap (n1, n4);
    }
    if (n1 > n5) {
        swap (n1, n5);
    }
    if (n2 > n3) {
        swap (n2, n3);
    }
    if (n2 > n4) {
        swap (n2, n4);
    }
    if (n2 > n5) {
        swap (n2, n5);
    }
    if (n3 > n4) {
        swap (n3, n4);
    }
    if (n3 > n5) {
        swap (n3, n5);
    }
    if (n4 > n5) {
        swap (n4, n5);
    }
    
    n1 = n2;
    n5 = n4;
    
    winsMean = ((n1 + n2 + n3 + n4 + n5) / 5.0);
    
    // <Extra Credit Output>
    
    cout << "Root Mean Square = " << rootMeanSquare << endl;
    cout << "20% Winsorized Mean = " << winsMean << endl;
    
    cout << "*** End Extra Credit ***" << endl;

    return 0;
}
