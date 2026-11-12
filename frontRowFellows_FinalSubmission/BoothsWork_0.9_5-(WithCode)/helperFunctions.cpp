/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#include "helperFunctions.h"

void enemySet(Enemy data[ ], const int eL, const int eW, color_t color){
    int count = 0;
    double x, y;
    for(int i = 0; i < eL; i++){
        for(int j = 0; j < eW; j++){
            x = data[count].getUL().x;
            y = data[count].getUL().y;
            data[count].setUL(point(x+ 74*j, y+ 60*i));
            data[count].setColor(color);
            data[count].setSprite();
            count++;
        }
    }
}
void enemySet2(Enemy data[ ], const int n){
    double x, y;
    for(int i = 0; i < 5; i++){
        x = data[i].getUL().x;
        y = data[i].getUL().y;
        data[i].setUL(point(x+ 74*i+287, y+170));
        data[i].setColor(WEISS);
        data[i].setSprite();
    }
}
void enemyDraw(SDL_Plotter& alfa, Enemy data[ ], const int eL, const int eW, int c, int spriteT[][15]){
    int count = 0;
    int scale = 2;
    int r, b;
    for(int i = 0; i < eL; i++){
        for(int j = 0; j < eW; j++){
            for(int k = 0; k < 15; k++){
                for(int l = 0; l < 15; l++){
                    if(c % 1000 > 500){
                        spriteT[k][l] = data[count].sprite[k][l];
                    }
                    else{
                        spriteT[k][l] = data[count].spriteB[k][l];
                    }
                    for(int m = 0; m < scale; m++){
                        for(int n = 0; n < scale; n++){
                            if(spriteT[k][l] && data[count].getAlive()){
                                r = data[count].getColor().R;
                                b = data[count].getColor().B;
                                if(spriteT[k][l] == 2){
                                    data[count].setColor(color_t(r, 100, b));
                                }
                                else if(spriteT[k][l] == 3){
                                    data[count].setColor(color_t(r, 200, b));
                                }
                                else {
                                    data[count].setColor(color_t(r, 0, b));
                                }
                                alfa.plotPixel(data[count].getUL().x+l*scale+m,
                                               data[count].getUL().y+k*scale+n,
                                               data[count].getColor().R, data[count].getColor().G, data[count].getColor().B);
                            }
                        }
                    }
                }
            }
            count++;
        }
    }
}

void enemyDraw2(SDL_Plotter& alfa, Enemy data[ ], const int eL, const int eW, int c, int spriteT[][15]){
    int count = 0;
    int scale = 2;
    int r, b;
    for(int i = 0; i < eL; i++){
        for(int j = 0; j < eW; j++){
            for(int k = 0; k < 15; k++){
                for(int l = 0; l < 15; l++){
                    if(c % 1000 > 500){
                        spriteT[k][l] = data[count].sprite[k][l];
                    }
                    else{
                        spriteT[k][l] = data[count].spriteB[k][l];
                    }
                    for(int m = 0; m < scale; m++){
                        for(int n = 0; n < scale; n++){
                            if(spriteT[k][l] && data[count].getAlive()){
                                if(spriteT[k][l] == 2){
                                    data[count].setColor(RED);
                                }
                                else if(spriteT[k][l] == 3){
                                    data[count].setColor(WEISS);
                                }
                                else {
                                    data[count].setColor(GOLD);
                                }
                                alfa.plotPixel(data[count].getUL().x+l*scale+m,
                                               data[count].getUL().y+k*scale+n,
                                               data[count].getColor().R, data[count].getColor().G, data[count].getColor().B);
                            }
                        }
                    }
                }
            }
            count++;
        }
    }
}

void setBack(SDL_Plotter& alfa, const int a, const int b){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            alfa.plotPixel(i,j,0,0,0);
        }
    }
}


// Function to move the objects to the LEFT_ARROW
void moveLeft(Enemy data[], const int eL, const int eW) {

    int count = 0;
    double x, y;

    for (int i = 0; i < eL; i++) {

        for (int j = 0; j < eW; j++) {
            x = data[count].getUL().x;
            y = data[count].getUL().y;
            data[count].setUL(point(x - 1, y));
            count++;
        }
    }
}

void moveRight(Enemy data[], const int eL, const int eW) {

    int count = 0;
    double x, y;

    for (int i = 0; i < eL; i++) {

        for (int j = 0; j < eW; j++) {
            x = data[count].getUL().x;
            y = data[count].getUL().y;
            data[count].setUL(point(x +1, y));
            count++;
        }
    }
}

void moveDown(Enemy data[], const int eL, const int eW) {

    int count = 0;
    double x, y;

    for (int i = 0; i < eL; i++) {

        for (int j = 0; j < eW; j++) {
            x = data[count].getUL().x;
            y = data[count].getUL().y;
            data[count].setUL(point(x, y + 20));
            count++;
        }
    }
}

void moveCycle(Enemy data[], const int eL, const int eW, int& murder) {
    //int murder = 0;
    //bool r;
    if(data[54].getUL().x+data[54].getLength() > 990){
        moveDown(data, eL, eW);
        murder++;
    }
    else if(data[0].getUL().x < 1){
        moveDown(data, eL, eW);
        murder++;
    }
    if(murder % 2 == 0){
        moveRight(data, eL, eW);
    }
    else{
        moveLeft(data, eL, eW);
    }
}

void moveCycle2(Enemy data[ ], Booth_t& booth, const int n, int& murder){
    if(data[4].getUL().x + data[4].getLength() > 990){
        murder++;
    }
    else if(data[0].getUL().x < 1){
        murder++;
    }
    if(murder % 2 == 0){
        moveLeft(data, 5, 1);
        booth.moveLeft();
    }
    else{
        moveRight(data, 5, 1);
        booth.moveRight();
    }
}

void bulletSet(Bullet data[ ], const int n, Ship ship){
    int x, y, l, l2;
    x = ship.getUL().x+10;
    y = ship.getUL().y+1;
    l = ship.getBL();
    bool shot = false;
    for(int i = 0; i < n && !shot; i++){
        l2 = data[i].getLength();
        if(data[i].getAv()){
            data[i].setUL(point(y+l/2-l2/4, x-l2));
            data[i].setAv(false);
            data[i].setColor(BLUE_L);
            shot = true;
        }
    }
}

// moves the bullet
void moveBullet(Bullet data[], const int n) {
    double x, y;

    for (int i = 0; i < n; i++) {
        if (data[i].getUL().y < 950 && data[i].getUL().y > 10) {
            x = data[i].getUL().x;
            y = data[i].getUL().y;
            data[i].setUL(point(x, y - 15));


        }
        else{
            data[i].setColor(GOLD);
            data[i].setUL(point(10*i+125,970));
            data[i].setAv(true);
        }
    }

}

void bulletDraw(SDL_Plotter& alfa, Bullet data[ ], const int n){
    for(int i = 0; i < n; i++){
        for(int x = data[i].getUL().x; x <= data[i].getUL().x+data[i].getLength()/4; x++){
            for(int y = data[i].getUL().y; y <= data[i].getUL().y+data[i].getLength(); y++){
                if(/*data[i].getUL().y < 950*/ true){
                    alfa.plotPixel(x, y, data[i].getColor().R, data[i].getColor().G, data[i].getColor().B);
                }
            }
        }
    }
}

bool bulletHit(Bullet data1[ ], const int n1, Enemy data2[ ], const int n2, Mix_Chunk* sound){
    bool hit = false;

    for(int i = 0; i < n1; i++){
        if(!data1[i].getAv()){
            for(int j = 0; j < n2; j++){
                //cout << "aim" << endl;
                if(data1[i].getUL().x > data2[j].getUL().x &&
                   data1[i].getUL().x < data2[j].getUL().x + data2[i].getLength() &&
                   data1[i].getUL().y > data2[j].getUL().y &&
                   data1[i].getUL().y < data2[j].getUL().y + data2[i].getLength() &&
                   data2[j].getAlive())
                {
                    data2[j].setAlive(false);
                    data1[i].setColor(GOLD);
                    data1[i].setUL(point(10,970));
                    data1[i].setAv(true);
                    hit = true;
                    Mix_PlayChannel(-1, sound, 0);
                }
            }
        }
    }

    return hit;
}

int randShipSelect(const int n){
    int dog;
    srand(clock());
    dog = rand()%n;
    return dog;
}

void enemyBulletSet(Bullet data[ ], const int n, Enemy en, Mix_Chunk* sound){
    int x, y, l, l2;
    x = en.getUL().x;
    y = en.getUL().y;
    l = en.getLength();
    bool shot = false;
    if(en.getAlive()){
        for(int i = 0; i < n && !shot; i++){
            l2 = data[i].getLength();
            if(data[i].getAv()){
                data[i].setUL(point(x+l/2-l2/8, y+l+l2/4-4));
                data[i].setAv(false);
                data[i].setColor(RED);
                shot = true;
                Mix_PlayChannel(-1, sound, 0);
            }
        }
    }
}

void moveEnemyBullet(Bullet data[ ], const int n, const int s){
    double x, y;

    for (int i = 0; i < n; i++) {
        if (data[i].getUL().y < 950 && data[i].getUL().y > 10) {
            x = data[i].getUL().x;
            y = data[i].getUL().y;
            data[i].setUL(point(x, y + s));
        }
        else{
            data[i].setColor(BLACK);
            data[i].setUL(point(990,970));
            data[i].setAv(true);
        }
    }
}

void enemyBulletHit(Bullet data[ ], const int n1, Ship& ship, int& lives, int& score){
    for(int i = 0; i < n1; i++){
        if(!data[i].getAv()){
            if(data[i].getUL().y > ship.getUL().x &&
                data[i].getUL().y < ship.getUL().x + ship.getBL() &&
               data[i].getUL().x + data[i].getLength()/4 > ship.getUL().y &&
                data[i].getUL().x < ship.getUL().y + ship.getBL())
                {
                    data[i].setColor(BLACK);
                    data[i].setUL(point(990,970));
                    data[i].setAv(true);
                    lives--;
                    score -= 100;
                }
        }
    }
}

void lifeBulletSet(Bullet data[ ], const int n){
    for(int i = 0; i < n; i++){
        data[i].setColor(GREEN);
        data[i].setUL(point(255 + 10*i ,970));
        data[i].setAv(true);
    }
}

bool checkEnemyPos(Enemy data[], const int n, bool& going2) {
    bool going = true;

    for (int i = n - 1; i >= 0; --i) {
        if (data[i].getAlive() && data[i].getUL().y > 840) {
            going = going2 = false;
        }
    }

    return going;
}

void drawLaser(SDL_Plotter& alfa, bool b, Booth_t bill, Bullet bullet[ ]) {
    if (b) {
        for (int i = bill.getUL().x + bill.getLength() / 2 - 5; i <= bill.getUL().x + bill.getLength() / 2 + 5; ++i) {
            for (int j = bill.getUL().y + bill.getLength(); j < 935; ++j) {
                alfa.plotPixel(i, j, 220, 0, 0);
            }
        }
        bullet[0].setUL(point(bill.getUL().x + bill.getLength() / 2 -2, 905));
        bullet[0].setAv(false);
        bullet[0].setColor(RED);
        bulletDraw(alfa, bullet,1);
    }
    else{
        bullet[0].setAv(true);
    }
}

bool boothHit(Bullet data1[ ], const int n1, Booth_t& bill) {
    bool hit = false;

    for(int i = 0; i < n1; i++){
        if(!data1[i].getAv()){
            if(data1[i].getUL().x > bill.getUL().x &&
                data1[i].getUL().x < bill.getUL().x + bill.getLength() &&
                data1[i].getUL().y > bill.getUL().y &&
                data1[i].getUL().y < bill.getUL().y + bill.getLength())
            {
                data1[i].setColor(GOLD);
                data1[i].setUL(point(10,970));
                data1[i].setAv(true);
                bill.setLives(bill.getLives() - 1);
                hit = true;
            }
        }
    }

    return hit;
}

void boothBulletSet(Bullet data[ ], const int n){
    for(int i = 0; i < n; i++){
        data[i].setColor(ORANGE);
        data[i].setUL(point(255 + 10*i ,50));
        data[i].setAv(true);
    }
}

void drawBooth(SDL_Plotter& alfa, Booth_t bill, bool i) {
    int scale = 3;
    for(int k = 0; k < 21; k++){
        for(int l = 0; l < 21; l++){
            for(int m = 0; m < scale; m++){
                for(int n = 0; n < scale; n++){
                    if(bill.sprite[i][k][l]){
                        if(bill.sprite[i][k][l] == 2){
                            bill.setColor(DARKGREY);
                        }
                        else if(bill.sprite[i][k][l] == 3){
                            bill.setColor(LIGHTGREY);
                        }
                        else if (bill.sprite[i][k][l] == 4) {
                            bill.setColor(SKIN1);
                        }
                        else if (bill.sprite[i][k][l] == 5) {
                            bill.setColor(SKIN2);
                        }
                        else if(bill.sprite[i][k][l] == 6){
                            bill.setColor(PINK);
                        }
                        else {
                            bill.setColor(WEISS);
                        }
                        alfa.plotPixel(bill.getUL().x+l*scale+m,
                                        bill.getUL().y+k*scale+n,
                                        bill.getColor().R, bill.getColor().G, bill.getColor().B);
                    }
                }
            }
        }
    }
}
