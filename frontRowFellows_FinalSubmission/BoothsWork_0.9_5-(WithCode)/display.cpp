/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#include "display.h"

void readIn(ifstream& in, string fName, int data[][7][7], const int l, const int d){
    char letter = 'z';

    in.open(fName);
    for(int i = 0; i < l && in; i++){
        in >> letter;
        for(int j = 0; j < d; j++){
            for(int k = 0; k < d; k++) {
                in >> data[i][j][k];
            }
        }
    }
    in.close();
}

void displayLower(SDL_Plotter& alfa, int data[][7][7], point p, int index, int s){
    int x = p.x;
    int y = p.y;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            for(int k = 0; k < s; ++k) {
                for (int l = 0; l < s; l++) {
                    if(data[index][i][j]){
                        alfa.plotPixel(y+j*s+l, x+i*s+k, 255, 255, 255);
                    }
                }
            }
        }
    }
}

void displayHigher(SDL_Plotter& alfa, int data[][7][7], point p, string str, int s) {
    int index = -1;

    for (unsigned int i = 0; i < str.size(); ++i) {
        p.y += s * 7;
        switch (tolower(str.at(i))) {
        case 'a':
            index = 0;
            break;
        case 'b':
            index = 1;
            break;
        case 'c':
            index = 2;
            break;
        case 'd':
            index = 3;
            break;
        case 'e':
            index = 4;
            break;
        case 'f':
            index = 5;
            break;
        case 'g':
            index = 6;
            break;
        case 'h':
            index = 7;
            break;
        case 'i':
            index = 8;
            break;
        case 'j':
            index = 9;
            break;
        case 'k':
            index = 10;
            break;
        case 'l':
            index = 11;
            break;
        case 'm':
            index = 12;
            break;
        case 'n':
            index = 13;
            break;
        case 'o':
            index = 14;
            break;
        case 'p':
            index = 15;
            break;
        case 'q':
            index = 16;
            break;
        case 'r':
            index = 17;
            break;
        case 's':
            index = 18;
            break;
        case 't':
            index = 19;
            break;
        case 'u':
            index = 20;
            break;
        case 'v':
            index = 21;
            break;
        case 'w':
            index = 22;
            break;
        case 'x':
            index = 23;
            break;
        case 'y':
            index = 24;
            break;
        case 'z':
            index = 25;
            break;
        case '0':
            index = 26;
            break;
        case '1':
            index = 27;
            break;
        case '2':
            index = 28;
            break;
        case '3':
            index = 29;
            break;
        case '4':
            index = 30;
            break;
        case '5':
            index = 31;
            break;
        case '6':
            index = 32;
            break;
        case '7':
            index = 33;
            break;
        case '8':
            index = 34;
            break;
        case '9':
            index = 35;
            break;
        case '-':
            index = 36;
            break;
        case ':':
            index = 37;
            break;
        case ' ':
            index = -1;
            break;

        }
        if(index >= 0){
            displayLower(alfa, data, p, index, s);
        }
    }
}
