/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <ostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "color.h"

using namespace std;

struct point{
    public:
    int x, y;
    color_t color;

    point();
    point(int, int);
    point(const point&);
    void display(ostream&);
    void draw(SDL_Plotter&);
    double distance(point);
};

#endif // POINT_H_INCLUDED
