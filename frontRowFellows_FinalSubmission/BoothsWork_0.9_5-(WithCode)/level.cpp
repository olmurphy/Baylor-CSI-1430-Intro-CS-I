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
    color_t enCol passes in r and b values for enemy sprites
    stringstream ss for getting different strings to declare music for the different levels
    char cint[7] referenced for the different level music
    string s1 holds the players current score
    string levelMusic holds the level music title
    int speed holds the speed of the enemy bullets
    int eBL holds the amounts of enemy bullets
    Ship ship declaration of ship class for use
    int eL length of enemy array
    int eW width of enemy array
    int bL player bullet amount
    Enemy enemy[eL*eW] declaration of enemy array
    Bullet c[bL] declaration of player bullet array
    Bullet eC[eBL] declaration of enemy bullet array
    Bullet l[lives] declaration of player lives for display
    enemySet(enemy, eL, eW, enCol) sets the enemy coordinates and sprites
    int start = clock() gets start value for clock for screen update
    int current representing current clock
    bool going keeps the level while loop running
    bool going2 tracks whether or not player has won
    bool allDead keeps track if all enemies are dead
    int murder passed in to enemy move cycle to update the direction
    int spriteT[15][15] holds current enemy sprite
*/

#include "level.h"
bool levelRun(SDL_Plotter& alfa, color_t color, int s, int a, int& lives, int& score, int mult, int data[ ][7][7]){
    color_t enCol = color;
    stringstream ss;
    char cint[7] = "012345";
    string s1;
    string levelMusic = "Level .mp3";
    levelMusic.at(5) = cint[mult];
    int speed = s;
    int eBL = a;
    Ship ship = Ship();
    int eL = 5, eW = 11, bL = 3;
    Enemy enemy[eL*eW];
    Bullet c[bL];
    Bullet eC[eBL];
    Bullet l[lives];
    enemySet(enemy, eL, eW, enCol);
    ship.setSprite();
    int start = clock();
    int current;
    bool going = true;
    bool going2 = false;
    bool allDead = false;
    int murder = 0;
    int spriteT[15][15] = {0};
    //Audio functions
    SDL_Init(SDL_INIT_AUDIO);
    //initialize SDL mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    //load large audio file
    //Mix_Music *backgroundSound = Mix_LoadMUS("Backgroundmusic.mp3");
    Mix_Music *backgroundSound2 = Mix_LoadMUS(levelMusic.c_str());
    //load small audio file
    Mix_Chunk *laserEffect = Mix_LoadWAV("Laser_Shoot.wav");
    Mix_Chunk *laserEffect2 = Mix_LoadWAV("Enemy_Laser.wav");
    Mix_Chunk *enemyHit = Mix_LoadWAV("Enemy_Die.wav");

    Mix_PlayMusic(backgroundSound2, -1);
    while(!alfa.getQuit() && going){
        //cout << score << endl;
        current = clock() - start;
        if (current % 2 == 0) {
            if(current % 2 == 0){
                going = checkEnemyPos(enemy, eL * eW, going2);
                moveCycle(enemy, eL, eW, murder);
            }

            if(current % 2 == 0){
                moveBullet(c, bL);
                moveEnemyBullet(eC, eBL, speed);
            }
            if(current % 15 == 0){
                enemyBulletSet(eC, eBL, enemy[randShipSelect(eL*eW)], laserEffect2);
            }
            lifeBulletSet(l, lives);
            setBack(alfa, ALFA_R, ALFA_C);
            for(int i = 0; i < ALFA_C; i++){
                for(int j = 0; j < 3; j++){
                    alfa.plotPixel(i,870+j, 100, 100, 100);
                }
            }
            displayHigher(alfa, data, point(973, 0), "Bullets", 2);
            displayHigher(alfa, data, point(973, 165), "Life", 2);
            ss.clear();
            ss << score;
            ss >> s1;
            s1 = "score " + s1;
            displayHigher(alfa, data, point(973, 800), s1, 2);
            if (bulletHit(c, bL, enemy, eL*eW, enemyHit)) {
                score += 30 + 10*mult;
            }
            enemyBulletHit(eC, eBL, ship, lives, score);
            ship.notDead(lives);
            if(ship.getAlive()){
                ship.draw2(alfa);
                //ship.draw(alfa);
            }
            else{
                going = false;
            }
            enemyDraw(alfa, enemy, eL, eW, current, spriteT);
            bulletDraw(alfa, eC, eBL);
            bulletDraw(alfa, c, bL);
            bulletDraw(alfa, l, lives);

            alfa.update();
        }

        if(alfa.kbhit()){
            char Key = alfa.getKey();

            switch (tolower(Key)) {
            case 'a':
            case LEFT_ARROW:
                for (int i = 0; i < 2; ++i) {
                    ship.moveLeft();
                    alfa.update();
                }
                break;

            case 'd':
            case RIGHT_ARROW:
                for (int i = 0; i < 2; ++i) {
                    ship.moveRight();
                    alfa.update();
                }
                break;

            case ' ':
                Mix_PlayChannel(-1, laserEffect, 0);
                bulletSet(c, bL, ship);
                break;
            case 'p':
                going2 = true;
                going = false;
                break;
            case 'f':
                going2 = going = Pause(alfa, data);
                break;
            default:
                alfa.update();
                break;

            }
        for (int i = 0; i < eL*eW; ++i) {
            if (!enemy[i].getAlive()) {
                allDead = true;
            }
            else {
                allDead = false;
                break;
            }
        }
        if (allDead) {
            going2 = true;
            going = false;
        }

        }
        alfa.update();

    }
    if(going2){
        cout << "level complete" << endl;
    }
    else{
        cout << "u ded boi" << endl;
    }

    //Mix_FreeMusic(backgroundSound);
    Mix_FreeMusic(backgroundSound2);
    Mix_FreeChunk(laserEffect);
    Mix_FreeChunk(laserEffect2);
    Mix_FreeChunk(enemyHit);
    return going2;
}

bool gameStart(SDL_Plotter& alfa, int data[ ][7][7]){
    bool going = true, going2 = false;
    //Audio functions
    SDL_Init(SDL_INIT_AUDIO);
    //initialize SDL mixer
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048);
    //load large audio file
    Mix_Music *backgroundSound3 = Mix_LoadMUS("Backgroundmusic2.mp3");
    //load small audio file
    Mix_Chunk *menuEffect = Mix_LoadWAV("Menu_Select.wav");
    Mix_Chunk *welcomeStudent = Mix_LoadWAV("Welcome_Student.wav");

    Mix_PlayChannel(-1, welcomeStudent, 0);
    //Mix_PlayMusic(backgroundSound3, 1);
    Mix_FadeInMusic(backgroundSound3, -1, 15000);
    while(!alfa.getQuit() && going){
        setBack(alfa, ALFA_R, ALFA_C);
        displayHigher(alfa, data, point(50, 100), "Booths final stand", 6);
        displayHigher(alfa, data, point(100 + 7*6, 275), "Main menu", 6);
        displayHigher(alfa, data, point(500, 305), "press s to start", 3);
        displayHigher(alfa, data, point(600, 245), "press c for how to play", 3);
        if(alfa.kbhit()){
            char Key = alfa.getKey();

            switch (tolower(Key)) {
            case 's':
                Mix_PlayChannel(-1, menuEffect, 0);
                going = false;
                break;
            case 'c':
                going = false;
                going2 = true;
                break;
            }
        }
        alfa.update();
    }
    Mix_FreeMusic(backgroundSound3);
    Mix_FreeChunk(welcomeStudent);
    Mix_FreeChunk(menuEffect);

    return going2;
}

bool gameEnd(SDL_Plotter& alfa, bool win, int data[][7][7], int score){
    stringstream ss;
    string s1;
    ss << score;
    ss >> s1;
    bool going = true;
    bool keepPlaying = false;
    //Audio functions
    SDL_Init(SDL_INIT_AUDIO);
    //initialize SDL mixer
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048);
    //load small audio file
    Mix_Chunk *endGame = Mix_LoadWAV("Booth_End.wav");
    Mix_Chunk *endGame2 = Mix_LoadWAV("Loose_Screen.wav");
    setBack(alfa, ALFA_R, ALFA_C);
    if(win){
        displayHigher(alfa, data, point(50, 310), "YOU WON", 6);
        Mix_PlayChannel(-1, endGame, 0);
        displayHigher(alfa, data, point(900, 230), "press s to play again", 3);
    }
    else{
        displayHigher(alfa, data, point(50, 280), "GAME OVER", 6);
        Mix_PlayChannel(-1, endGame2, 0);
        displayHigher(alfa, data, point(900, 230), "press s to try again", 3);
    }
    displayHigher(alfa, data, point(500, 270), "Your score is:", 4);
    displayHigher(alfa, data, point(550, 500 - 21*s1.size()), s1, 4);
    displayHigher(alfa, data, point(800, 315), "press q to quit", 3);
    while(!alfa.getQuit() && going){
        if(alfa.kbhit()){
            char Key = alfa.getKey();

            switch (tolower(Key)) {
            case 'q':
                going = false;
                break;
            case 's':
                going = false;
                keepPlaying = true;
            }
        }
        alfa.update();
    }
    Mix_FreeChunk(endGame);
    Mix_FreeChunk(endGame2);
    return keepPlaying;
}

void betweenScreen(SDL_Plotter& alfa, int i, int data[][7][7]){
    bool going = true;
    stringstream ss;
    ss << "level " << i;
    char cint[8] = "0123456";
    string lAdded = "  lives added";
    lAdded.at(0) = cint[i - 1];
    string level, wavName = "Level .wav";
    wavName.at(5) = cint[i];
    getline(ss, level);
    //Audio functions
    SDL_Init(SDL_INIT_AUDIO);
    //initialize SDL mixer
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048);
    //load small audio file
    Mix_Chunk *levelx = Mix_LoadWAV(wavName.c_str());
    setBack(alfa, ALFA_R, ALFA_C);
    if (i < 6) {
        displayHigher(alfa, data, point(50, 310), level, 6);
    }
    else {
        displayHigher(alfa, data, point(50, 197), "Booth Battle", 6);
    }
    if (i > 2 && i <= 6) {
        displayHigher(alfa, data, point(250, 250), lAdded, 4);
    }
    else if (i == 2) {
        displayHigher(alfa, data, point(250, 250), "1 life added", 4);
    }
    displayHigher(alfa, data, point(500, 255), "press c to start level", 3);
    Mix_PlayChannel(-1, levelx, 0);
    while(!alfa.getQuit() && going){
        if(alfa.kbhit()){
            char Key = alfa.getKey();
            //displayHigher(alfa, data, point(900, 315), "there is no god", 3);

            switch (tolower(Key)) {
            case 'c':
                going = false;
                break;
            }
        }
        alfa.update();
    }
    Mix_FreeChunk(levelx);
}
/*
Data Abstraction:
    bool uIsFucked tracks whether or not booth laser of death is activated
    int current2 tracks how long laser is shot
    int current3 tracks how long until enemies are respawned
*/
bool finalBattle(SDL_Plotter& alfa, int& lives, int& score, int data[ ][7][7]){
    stringstream ss;
    string s1;
    Ship ship = Ship();
    int bL = 3, eBL = 3, murder = 0;
    Enemy enemy[5];
    enemySet2(enemy, 5);
    Booth_t booth;
    Bullet c[bL];
    Bullet eC[eBL];
    Bullet l[100];
    Bullet boothL[booth.getLives()];
    Bullet bC[1];
    ship.setSprite();
    booth.setSprite();
    int start = clock();
    long long current, current2, current3;
    bool going = true;
    bool going2 = false;
    bool allDead = false;
    bool uIsFucked = true, b = true, b2 = true;
    int spriteT[15][15] = {0};
    //Audio functions
    SDL_Init(SDL_INIT_AUDIO);
    //initialize SDL mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    //load large audio file
    Mix_Music *backgroundSound2 = Mix_LoadMUS("Level6.mp3");
    //load small audio file
    Mix_Chunk *laserEffect = Mix_LoadWAV("Laser_Shoot.wav");
    Mix_Chunk *laserEffect2 = Mix_LoadWAV("Enemy_Laser.wav");
    Mix_Chunk *enemyHit = Mix_LoadWAV("Enemy_Die.wav");
    Mix_Chunk *boothHurt = Mix_LoadWAV("Booth_Hurt.wav");
    Mix_Chunk *boothLaser = Mix_LoadWAV("Booth_Laser.wav");

    Mix_PlayMusic(backgroundSound2, -1);
    while(!alfa.getQuit() && going){
        current = clock() - start;
        if (current % 2 == 0) {
            if(current % 2 == 0){
                // ADD booth and enemy cycle
                moveCycle2(enemy, booth, 5, murder);
            }

            if(current % 2 == 0){
                moveBullet(c, bL);
                moveEnemyBullet(eC, eBL, 10);
                //alfa.update();
            }
            if(current % 15 == 0){
                enemyBulletSet(eC, eBL, enemy[randShipSelect(5)], laserEffect2);
                //alfa.update();
            }
            if(!enemy[2].getAlive()){
                if(b2){
                    current3 = clock();
                    b2 = false;
                }
                if(clock() - current3 > 2000){
                    if(!uIsFucked){
                        uIsFucked = 1;
                    }
                    else {
                        uIsFucked = 0;
                    }
                    b2 = true;
                }
            }
            if(allDead){
                if(b){
                    lives += 2;
                    current2 = clock();
                    b = false;
                }
                if(clock() - current2 > 10000){
                    for(int i = 0; i < 5; i++){
                        enemy[i].setAlive(true);
                        //alfa.update();
                    }
                    b = true;
                    allDead = false;
                }
            }
            if (!booth.getLives()) {
                going = false;
                going2 = true;
            }
            lifeBulletSet(l, lives);
            boothBulletSet(boothL, booth.getLives());
            setBack(alfa, ALFA_R, ALFA_C);
            for(int i = 0; i < ALFA_C; i++){
                for(int j = 0; j < 3; j++){
                    alfa.plotPixel(i,870+j, 100, 100, 100);
                }
            }
            displayHigher(alfa, data, point(53, 90), "Booth Life", 2);
            displayHigher(alfa, data, point(973, 0), "Bullets", 2);
            displayHigher(alfa, data, point(973, 165), "Life", 2);
            ss.clear();
            ss << score;
            ss >> s1;
            s1 = "score " + s1;
            displayHigher(alfa, data, point(973, 800), s1, 2);
            if (bulletHit(c, bL, enemy, 5, enemyHit)) {
                score += 100;
            }
            if(boothHit(c, bL, booth)){
                score += 200;
                Mix_PlayChannel(-1, boothHurt, 0);
            }
            enemyBulletHit(eC, eBL, ship, lives, score);
            enemyBulletHit(bC, 1, ship, lives, score);
            ship.notDead(lives);
            if(ship.getAlive()){
                ship.draw2(alfa);
                //ship.draw(alfa);
            }
            else{
                going = false;
            }
            drawLaser(alfa, !enemy[2].getAlive() && !uIsFucked, booth, bC);
            if(!uIsFucked){
                Mix_PlayChannel(-1, boothLaser, 0);
            }
            enemyDraw2(alfa, enemy, 5, 1, current, spriteT);
            bulletDraw(alfa, eC, eBL);
            bulletDraw(alfa, c, bL);
            bulletDraw(alfa, l, lives);
            bulletDraw(alfa, boothL, booth.getLives());
            drawBooth(alfa, booth, uIsFucked);
            alfa.update();
        }

        if(alfa.kbhit()){
            char Key = alfa.getKey();

            switch (tolower(Key)) {
            case 'a':
            case LEFT_ARROW:
                for (int i = 0; i < 2; ++i) {
                    ship.moveLeft();
                    alfa.update();
                }
                break;

            case 'd':
            case RIGHT_ARROW:
                for (int i = 0; i < 2; ++i) {
                    ship.moveRight();
                    alfa.update();
                }
                break;

            case ' ':
                Mix_PlayChannel(-1, laserEffect, 0);
                bulletSet(c, bL, ship);
                break;
            case 'p':
                going2 = true;
                going = false;
                break;
            case 'f':
                going2 = going = Pause(alfa, data);
                break;
            default:
                alfa.update();
                break;

            }
        for (int i = 0; i < 5; ++i) {
            if (!enemy[i].getAlive()) {
                allDead = true;
            }
            else {
                allDead = false;
                break;
            }
        }
        /*if (allDead) {
            going2 = true;
            going = false;
        }*/

        }
        alfa.update();

    }
    if(going2){
        cout << "level complete" << endl;
    }
    else{
        cout << "u ded boi" << endl;
    }

    //Mix_FreeMusic(backgroundSound);
    Mix_FreeMusic(backgroundSound2);
    Mix_FreeChunk(laserEffect);
    Mix_FreeChunk(laserEffect2);
    Mix_FreeChunk(enemyHit);
    Mix_FreeChunk(boothHurt);
    Mix_FreeChunk(boothLaser);
    return going2;
}

bool Pause(SDL_Plotter& alfa, int data[][7][7]) {
    bool going = true, going2 = true;

    while(!alfa.getQuit() && going){
        setBack(alfa, ALFA_R, ALFA_C);
        displayHigher(alfa, data, point(50, 320), "Pause", 6);
        displayHigher(alfa, data, point(500, 270), "press c to return to battle", 3);
        displayHigher(alfa, data, point(550, 270), "press q to quit game", 3);
        if(alfa.kbhit()){
            char Key = alfa.getKey();
            //displayHigher(alfa, data, point(900, 315), "there is no god", 3);

            switch (tolower(Key)) {
            case 'q':
                going2 = false;
            case 'c':
                going = false;
                break;
            }
        }
        alfa.update();
    }

    return going2;
}

void howToPlay(SDL_Plotter& alfa, int data[][7][7]) {
    bool going = true;


    setBack(alfa, ALFA_R, ALFA_C);
    displayHigher(alfa, data, point(50, 270), "How To Play", 6);
    displayHigher(alfa, data, point(300, 100), "LeftArrow   - Move ship left", 3);
    displayHigher(alfa, data, point(350, 100), "RightArrow  - Move ship right", 3);
    displayHigher(alfa, data, point(400, 100), "SPACE       - Shoot", 3);
    displayHigher(alfa, data, point(500, 100), "Press F to pause", 3);
    displayHigher(alfa, data, point(600, 100), "Dont let enemies past the gray line", 3);
    displayHigher(alfa, data, point(650, 100), "Kill all enemies to complete the level", 3);
    displayHigher(alfa, data, point(800, 100), "press c to return to main screen", 3);
    while(!alfa.getQuit() && going){
        if(alfa.kbhit()){
            char Key = alfa.getKey();
            //displayHigher(alfa, data, point(900, 315), "there is no god", 3);

            switch (tolower(Key)) {
                case 'c':
                    going = false;
                    break;
            }
        }
        alfa.update();
    }
}
