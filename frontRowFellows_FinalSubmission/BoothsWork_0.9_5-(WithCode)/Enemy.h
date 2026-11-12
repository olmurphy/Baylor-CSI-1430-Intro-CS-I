/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "point.h"
#include "color.h"
#include <fstream>

class Enemy {
private:
    bool isAlive;
    point uL;
    int length;
    color_t color;

public:
    Enemy();

    int sprite[15][15];
    int spriteB[15][15];

    void setAlive(const bool);
    void setUL(const point);
    void setLength(const int);
    void setColor(const color_t);

    /*
    Description:
        sets the sprite fore the enemy class
    Return:
        void return type
    Precondition:
        takes in no parameters
    Postcondition:
        values are unchanged
    */
    void setSprite();

    bool getAlive() const;
    point getUL() const;
    int getLength() const;
    color_t getColor() const;

    void draw(SDL_Plotter&);
};

#endif // ENEMY_H_INCLUDED
