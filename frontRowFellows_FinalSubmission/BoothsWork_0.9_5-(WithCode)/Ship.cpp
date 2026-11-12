/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#include "Ship.h"

Ship::Ship(){
    uL.x = ALFA_R-100;
    uL.y = ALFA_C/2;
    bL = 30;
    isAlive = 1;
    int sprite[15][15] = {0};
    color_t c = SILVER;
    //lives = 3;
}

void Ship::setUL(const point p){
    uL = p;
}
void Ship::setBL(const int l){
    bL = l;
}

void Ship::setAlive(bool a) {
    isAlive = a;
}

void Ship::setSprite(){
    ifstream in;
    in.open("galaga.dat");
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            in >> sprite[i][j];
        }
    }
    in.close();
}

point Ship::getUL() const{
    return uL;
}
int Ship::getBL() const{
    return bL;
}

bool Ship::getAlive() const{
    return isAlive;
}

void Ship::draw(SDL_Plotter& alfa) const{
    for(int i = uL.x; i <= uL.x+bL; i++){
        for(int j = uL.y; j <= uL.y+bL; j++){
            alfa.plotPixel(j,i,200,200,0);
        }
    }
}

void Ship::draw2(SDL_Plotter& alfa) const{
    int scale = 2;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            for(int k = 0; k < scale; ++k) {
                for (int l = 0; l < scale; l++) {
                    if(sprite[i][j]){
                        if(sprite[i][j] == 2){
                            alfa.plotPixel(uL.y+j*scale+l, uL.x+i*scale+k, 255, 0, 0);
                        }
                        else if(sprite[i][j] == 3){
                            alfa.plotPixel(uL.y+j*scale+l, uL.x+i*scale+k, 0, 0, 255);
                        }
                        else{
                            alfa.plotPixel(uL.y+j*scale+l, uL.x+i*scale+k, 255, 255, 255);
                        }
                        //alfa.plotPixel()
                    }
                }
            }
        }

    }
}

void Ship::moveLeft() {
    if(uL.y > 10){
        uL.y -= 10;
    }
}

void Ship::moveRight() {
    if(uL.y + bL < 990){
        uL.y += 10;
    }
}

void Ship::notDead(int& n){
    if(n < 1){
        isAlive = false;
    }
}


