/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#include "Enemy.h"

Enemy::Enemy(){
    isAlive = true;
    uL = point(50,10);
    length = 30;
    color = BLUE;
}

void Enemy::setAlive(const bool a){
    isAlive = a;
}
void Enemy::setUL(const point u){
    uL = u;
}
void Enemy::setLength(const int l){
    length = l;
}
void Enemy::setColor(const color_t c){
    color = c;
}

void Enemy::setSprite(){
    ifstream in;
    in.open("enemy.dat");
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            in >> sprite[i][j];
        }
    }
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            in >> spriteB[i][j];
        }
    }
    in.close();
}

bool Enemy::getAlive() const{
    return isAlive;
}
point Enemy::getUL() const{
    return uL;
}
int Enemy::getLength() const{
    return length;
}
color_t Enemy::getColor() const{
    return color;
}

void Enemy::draw(SDL_Plotter& alfa){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            alfa.plotPixel(j, i, color.R, color.G, color.B);
        }
    }
}

