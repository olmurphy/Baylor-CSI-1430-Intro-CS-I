/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

/*
Data Abstraction:
    SDL_Plotter alfa(ALFA_R,ALFA_C) SDL plotter is declared
    color_t enCol declares color to be passed in for enemies
    ifstream in ifstream for reading in sprite map data from dat files
    int lNum amount of letter/number sprites in array
    int letters[lNum][7][7] declares array to be used for letter/number characters
    bool going used to track whether or not level is running
    int plrLives tracks player lives
    int enBS tracks enemy speed
    int enBA tracks enemy amount
    int score tracks player score
Input:
    Reads in sprites from dat files
    takes in user keystrokes
Process:
    Level function and subsidiary functions
    are called
Output:
    SDL plotter plots data given by level
    function
Assumptions:
    Player will not find 'p' dev button
    Player will make an attempt to
    beat the game
*/
#include <iostream>
#include <cctype>
#include <ctime>
#include <fstream>
#include <string>

#include "SDL_Plotter.h"
#include "Ship.h"
#include "Enemy.h"
#include "helperFunctions.h"
#include "Bullet.h"
#include "level.h"
#include "display.h"
#include "Booth.h"

using namespace std;

const string LET = "letters.dat";

int main(int argc, char** argv)
{
    // Data Abstraction
    SDL_Plotter alfa(ALFA_R,ALFA_C);
    color_t enCol;
    ifstream in;
    int lNum = 38;
    int letters[lNum][7][7];
    readIn(in, LET, letters, lNum, 7);
    bool going;
    int plrLives;
    int enBS;
    int enBA;
    int score;

    do {
        enCol = color_t(0, 0, 255);
        going = true;
        plrLives = 3;
        enBS = 5;
        enBA = 3;
        score = 0;

        while(gameStart(alfa, letters)) {
            howToPlay(alfa, letters);
        }

        for(int i = 1; i <= 5 && going; ++i){
            betweenScreen(alfa, i, letters);
            going = levelRun(alfa, enCol, enBS, enBA, plrLives, score, i, letters);
            enBS += 1;
            enBA += 3;
            plrLives += i;
            enCol = color_t(55 * (i), 0, 255 - 55 * (i));
        }

        if (going) {
            betweenScreen(alfa, 6, letters);
            going = finalBattle(alfa, plrLives, score, letters);
        }
    } while(gameEnd(alfa, going, letters, score));
    return 0;
}
