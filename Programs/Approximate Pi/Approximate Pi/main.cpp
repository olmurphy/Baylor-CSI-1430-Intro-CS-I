/*
Author: Owen Murphy
Assignment Title: Approximate Pi
Assignment Description: Write a program that approximates Pi
Due Date: 09/06/2019
Date Created: 08/30/2019
Date Last Modified: 09/09/2019
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    
    double pi1, pi2, pi;
    
    cout << setprecision(5) << fixed;
    pi1 = 4 * (1.0 - (1.0 / 3) + (1.0 / 5) - (1.0 / 7) + (1.0 / 9) - (1.0 / 11));
    pi2 = 4 * (1.0 - (1.0 / 3) + (1.0 / 5) - (1.0 / 7) + (1.0 / 9) - (1.0 / 11)
              + (1.0 / 13));
    
    cout << "PI = " << pi1 << endl;
    cout << "PI = " << pi2 << endl;
    
    
    cout << "*** Start Extra Credit ***" << endl;
    
    // <Extra Credit Output>
    
    double n = 1.0;
    
    pi = 4 * (n - (n / 3) + (n / 5) - (n / 7) + (n / 9) - (n / 11) + (n / 13)
              - (n / 15) + (n / 17) - (n / 19) + (n / 21) - (n / 23) + (n / 25)
              - (n / 27) + (n / 29) - (n / 31) + (n / 33) // This is 32
              - (n / 33) + (n / 35) - (n / 37) + (n / 39) - (n / 41) + (n / 43)
              - (n / 45) + (n / 47) - (n / 49) + (n / 43) - (n / 43) + (n / 45)
              - (n / 47) + (n / 49) - (n / 51) + (n / 53) - (n / 55) + (n / 57)
              - (n / 59) + (n / 61) - (n / 63) + (n / 65) - (n / 67) + (n / 69)
              - (n / 71) + (n / 73) - (n / 75) + (n / 77) - (n / 79) + (n / 81)
              - (n / 83) + (n / 85) - (n / 87) + (n / 89) - (n / 91) + (n / 93)
              - (n / 95) + (n / 97) - (n / 99)
              + (n / 101) - (n / 103) + (n / 105) - (n / 107)
              + (n / 109) - (n / 111) + (n / 113) - (n / 115)
              + (n / 117) - (n / 119) + (n / 121) - (n / 123)
              + (n / 125) - (n / 127) + (n / 129) - (n / 131)
              + (n / 133) - (n / 135) + (n / 137) - (n / 139)
              + (n / 141) - (n / 143) + (n / 145) - (n / 147)
              + (n / 149) - (n / 151) + (n / 153) - (n / 155)
              + (n / 157) - (n / 159) + (n / 161) - (n / 163)
              + (n / 165) - (n / 167) + (n / 169) - (n / 171)
              + (n / 173) - (n / 175) + (n / 177) - (n / 179)
              + (n / 181) - (n / 183) + (n / 185) - (n / 187)
              + (n / 189) - (n / 191) + (n / 193) - (n / 195)
              + (n / 197) - (n / 199) + (n / 201) - (n / 203)
              + (n / 205) - (n / 207) + (n / 209) - (n / 211)
              + (n / 213) - (n / 215) + (n / 217) - (n / 219)
              + (n / 221) - (n / 223) + (n / 225) - (n / 227)
              + (n / 229) - (n / 231) + (n / 233) - (n / 235)
              + (n / 237) - (n / 239) + (n / 241) - (n / 243)
              + (n / 245) - (n / 247) + (n / 249) - (n / 251)
              + (n / 253) - (n / 255) + (n / 257) - (n / 259)
              
              );
    
              
    
    cout << setprecision(2) << fixed;
    cout << "PI = " << pi << endl;
    
    
    cout << "*** End Extra Credit ***" << endl;
    // CHANGE DATE LAST MODIFIED
    
    
    return 0;
}
