/*
 
 */

#include "point.h"
#include "color.h"

point::point() {
    x = y = 0;
    c = BLACK;
    
}

point::point(int a, int b) {
    x = a;
    y = b;
    c = BLACK;
}

point::point(const point& p) {
    x = p.x;
    y = p.y;
    c = p.c;
}


void point::draw(SDL_Plotter& g) {
    if (x >= 0 && x < g.getCol() && y >= 0 && y < g.getRow()) {
        g.plogPixel(x, y, c.R, c.B, c.B);
    }
}

void point::display(ostream& os) {
    os << "(" << x << "," << y << ")";
}

double point::distance(point p) {
    return (sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)));
}
