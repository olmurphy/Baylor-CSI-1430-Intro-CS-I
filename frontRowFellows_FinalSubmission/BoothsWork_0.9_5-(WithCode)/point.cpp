/*
Author: Front Row Fellows:
Assignment Title: Booths final Stand
Assignment Description: Write a video inspired by space invaders
    Program has 5 levels, boos, start/end/pause/home screen
Due Date: 12/09/2019
Date Created: 11/20/2019
Date Last Modified: 12/09/2019
*/

#include "point.h"

point :: point(){
    x = y = 0;
    color = BLACK;
}
point :: point(int a, int b){
    x = a;
    y = b;
}
point :: point(const point& p){
    x = p.x;
    y = p.y;
    color = p.color;
}

void point :: draw(SDL_Plotter& g){
    if(x >= 0 && x < g.getCol() && y >= 0 && y < g.getRow()){
        g.plotPixel(x,y,color.R,color.G,color.B);
    }
}

void point :: display(ostream& os){
    os << "(" << x << "," << y << ")";
}
double point :: distance(point p){
    return (sqrt(pow(x-p.x,2)+pow(y-p.y,2)));
}
