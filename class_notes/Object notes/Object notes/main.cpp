//
//  main.cpp
//  Object notes
//
//  Created by Owen Murphy on 11/8/19.
//  Copyright © 2019 Owen Murphy. All rights reserved.
//

#include <iostream>
#include "point.h"
#include <ctime>
#include "Line.h"
#include "rectangle.h"
#include "SDL_Plotter.h"
#include "circle.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    SDL_Plotter g(1000, 1000);
    g.initSound("nameOfFile.wav");
    g.initSound("nameOfFile.wav");
    int count = 0;
    rectangle_t box[100];
    srand(time(0));
 
    circle_t ball[99];

    for (int i = 0; i < 99; i++) {
        ball[i].setCenter(point(rand()%g.getCol(), rand()%g.getCol()));
        ball[i].setRadius(rand()%100);
        ball[i].setColor(color(rand() % 256, rand() % 256, rand() % 256));
    }
    
    while (!g.getQuit()) {
        if (g.kbhit()) {
            char Key = g.getKey();
            
            switch (Key) {
                case 'P':
                    g.playSound("nameOfFile.wav");
                    // g.quitSound // if you do this, you have to init sound again
                    break;
                    
                default:
                    break;
            }
        }
        
        for (int i = 0; i < 99; i++) {
            ball[i].draw(g);
        }
        
        g.update() // draws all balls then displays
        g.playSound("nameOfFile.wav");
        for (int i = 0; i < 99; i++) {
            ball[i].setCenter(point(rand()%g.getCol(), rand() % g.getCol()));
            ball[i].setRadius(rand() % 100);
            ball[i].setColor(color(rand() % 256, rand() % 256, rand() % 256));
        }
    }
    
    
    
    
    return 0;
}
// when an object is instantiated the implicit constructor is invoked
