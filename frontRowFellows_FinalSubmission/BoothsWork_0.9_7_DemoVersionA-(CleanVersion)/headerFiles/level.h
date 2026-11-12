#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "helperFunctions.h"
#include "SDL_Plotter.h"
#include "Enemy.h"
#include "color.h"
#include "Bullet.h"
#include "Ship.h"
#include "point.h"
#include "display.h"
#include "Booth.h"

using namespace std;

/*
Description:
    runs major functions for
    level
Return:
    returns going
Precondition:
    going is true
Postcondition:
    level things happen
*/
bool levelRun(SDL_Plotter&, color_t, int, int, int&, int&, int, int [ ][7][7]);
/*
Description:
    runs major functions for
    start screen
Return:
    returns void type
Precondition:
    program is running
Postcondition:
    start things happen
*/
bool gameStart(SDL_Plotter&, int [][7][7]);
/*
Description:
    runs major functions for
    level
Return:
    returns going
Precondition:
    going2 is false
Postcondition:
    end things happen
*/
bool gameEnd(SDL_Plotter&, bool, int [][7][7], int);
/*
Description:
    displays the inbetween screen
    for each level
Return:
    returns void type
Precondition:
    level is passed
Postcondition:
    level things happen
*/
void betweenScreen(SDL_Plotter&, int, int [][7][7]);
/*
Description:
    runs major functions for
    final battle
Return:
    returns bool type
Precondition:
    level 5 is passed
Postcondition:
    final battle things happen
*/
bool finalBattle(SDL_Plotter& alfa, int& lives, int& score, int data[ ][7][7]);

bool Pause(SDL_Plotter&, int [][7][7]);

void howToPlay(SDL_Plotter&, int [][7][7]);

#endif // LEVEL_H_INCLUDED
