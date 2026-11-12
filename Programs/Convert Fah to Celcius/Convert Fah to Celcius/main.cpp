/*
 Author: Owen Murphy
 Assignment Title: Convert Fahrenheit to Celcius
 Assignment Description: Write a program to calculate from fahrenheit Cel
 Due Date: 09/09/2019
 Date Created: 09/04/2019
 Date Last Modified: 09/09/2019
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

/*
 Data Abstraction
 double fahren, celsius;
*/

using namespace std;
int main() {
    
    cout << setprecision(2) << fixed;
    
    double fahren, celsius;
    
    cout << "Enter a degree in Fahrenheit: " << endl;
    
    cin >> fahren;
    cout << fahren;
    cout << " " << fahren;
    
    // Formula and Calculate
    celsius = (fahren - 32.0) / (1.8);
    
    // Output calculation
    cout << " Fahrenheit is " << celsius << " Celsius" << endl;
    
    
    
    cout << "*** Start Extra Credit ***" << endl;
    
    // <Extra Credit Output>
    
    // Declare var
    double kelvin, rankine, delisle;
    
    // convert to degrees Kelvin, Rankine, and Delisle
    // Display output  (for each Kelvin, Rankine, and Delisle
    
    kelvin = (fahren - 32) * (static_cast<double>(5) / 9) + 273.15;
    rankine = fahren + 459.67;
    delisle = (212 - fahren) * (static_cast<double>(5) / 6);
    
    cout << fahren << " Fahrenheit is " << kelvin << " Kelvin" << endl;
    cout << fahren << " Fahrenheit is " << rankine << " Rankine" << endl;
    cout << fahren << " Fahrenheit is " << delisle << " Delisle" << endl;
    
    cout << "*** End Extra Credit ***" << endl;
    
    
    
    
    
    
    
    
    return 0;
}
