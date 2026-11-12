/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#include "Booth.h"

Booth_t::Booth_t(){
    lives = 50;
    length = 63;
    uL = point(500 - length/2,100);
    color = WEISS;
}

void Booth_t::setLives(const int l) {
    lives = l;
}

void Booth_t::setUL(const point p) {
    uL = p;
}

void Booth_t::setLength(const int l) {
    length = l;
}

void Booth_t::setColor(const color_t c) {
    color = c;
}

int Booth_t::getLives() const {
    return lives;
}

point Booth_t::getUL() const {
    return uL;
}

int Booth_t::getLength() const {
    return length;
}

color_t Booth_t::getColor() const {
    return color;
}

void Booth_t::draw(SDL_Plotter& alfa) {
    for (int i = uL.x; i < uL.x + length; ++i) {
        for (int j = uL.y; j < uL.y + length; ++j) {
            alfa.plotPixel(i, j, color.R, color.G, color.B);
        }
    }
}

void Booth_t::moveLeft() {
    uL.x -= 1;
}

void Booth_t::moveRight() {
    uL.x += 1;
}

void Booth_t::setSprite(){
    ifstream in;
    in.open("booth.dat");
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            in >> sprite[0][i][j];
        }
    }
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            in >> sprite[1][i][j];
        }
    }
    in.close();
}
