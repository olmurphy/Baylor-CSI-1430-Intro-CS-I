/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#include "Bullet.h"

Bullet::Bullet(){
    isAv = true;
    uL.x = 10;
    uL.y = 970;
    color = GREEN;
    length = 20;
}

void Bullet::setAv(const bool a){
    isAv = a;
}

void Bullet::setUL(const point u){
    uL = u;
}
void Bullet::setColor(const color_t c){
    color = c;
}
void Bullet::setLength(const int l){
    length = l;
}

bool Bullet::getAv() const{
    return isAv;
}

point Bullet::getUL() const{
    return uL;
}
color_t Bullet::getColor() const{
    return color;
}
int Bullet::getLength() const{
    return length;
}

void Bullet::moveBullet(){
    if(uL.x < 400){
        uL.x += 10;
    }
    else{
        color = BLACK;
    }
}

void Bullet::drawBullet(SDL_Plotter& alfa){
    for(int i = uL.x; i < uL.x + length; i++){
        for(int j = uL.y; j < uL.y + length/2; j++){
            alfa.plotPixel(j, i, color.R, color.G, color.B);
        }
    }
}
