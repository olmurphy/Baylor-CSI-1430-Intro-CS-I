#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>

#include "SDL_Plotter.h"
#include "point.h"

using namespace std;

/*
Description:
    reads in displaying values
    for letters / numbers
Return:
    void return type
Precondition:
    ifstream exists
    fName exists
    array exists
Postcondition:
    array is full
*/
void readIn(ifstream&, string, int [][7][7], const int, const int);
/*
Description:
    displays letter / number
Return:
    void return type
Precondition:
    SDL_Plot exists
    array exists
    point exists
    index exists
Postcondition:
    letter / number is displayed
    to SDL_Plot
*/
void displayLower(SDL_Plotter&, int [][7][7], point, int, int);
/*
Description:
    displays strings
Return:
    void return type
Precondition:
    SDL_Plot exists
    array exists
    point exists
    length exists
    string exists
Postcondition:
    string is displayed
    to SDL_Plot
*/
void displayHigher(SDL_Plotter&, int[][7][7], point, string, int);

#endif // DISPLAY_H_INCLUDED
