/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#ifndef BOOTH_H_INCLUDED
#define BOOTH_H_INCLUDED

#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "SDL_Plotter.h"
#include "Enemy.h"
#include "color.h"
#include "Bullet.h"
#include "Ship.h"
#include "point.h"

class Booth_t{
private:
    int lives;
    point uL;
    int length;
    color_t color;

public:
    Booth_t();

    int sprite[2][21][21];
    void setLives(const int);
    void setUL(const point);
    void setLength(const int);
    void setColor(const color_t);

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

    int getLives() const;
    point getUL() const;
    int getLength() const;
    color_t getColor() const;

    void moveLeft();
    void moveRight();

    void draw(SDL_Plotter&);
};


#endif // BOOTH_H_INCLUDED
