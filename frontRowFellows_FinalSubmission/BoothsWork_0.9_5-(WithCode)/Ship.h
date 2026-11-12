/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "point.h"
#include "color.h"

#include <fstream>

using namespace std;

const int ALFA_R = 1000;
const int ALFA_C = 1000;

class Ship{
    point uL;
    int bL;
    bool isAlive;
    int sprite[15][15];
    color_t c;
    //int lives;
public:
    Ship();

    void setUL(const point p);
    void setBL(const int l);
    void setAlive(bool);

    /*
    Description:
        sets the sprite fore the booth class
    Return:
        void return type
    Precondition:
        takes in no parameters
    Postcondition:
        values are unchanged
    */
    void setSprite();

    point getUL() const;
    int getBL() const;
    bool getAlive() const;

    void moveLeft();
    void moveRight();
    void draw(SDL_Plotter& alfa) const;
    void draw2(SDL_Plotter& alfa) const;

    void notDead(int&);

};

#endif // SHIP_H_INCLUDED
