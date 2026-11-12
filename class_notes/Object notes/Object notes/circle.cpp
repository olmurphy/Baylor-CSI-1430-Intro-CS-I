#include "circle.h"


circle_t::circle_t() {
    center = point(0, 0);
    radius = 1;
    c = RED;
}

circle_t::circle_t(double r, point cent, color col) {
    radius = r;
    center = cent;
    c = col;
}

circle_t::circle_t(const circle_t& other) {
    radius = other.radius;
    center = other.center;
    c = other.c;
}

void circle_t::setRadius(double r) {
    radius = r;
}

void circle_t::setCenter(point p) {
    center = p;
}

void circle_t::setColor(color col) {
    c = col;
}

double circle_t::getRadius() const {
    return radius;
}

point circle_t::getCenter() const { // pass by value;
    return center;
}

color circle_t::getColor() const{
    return c;
}

void circle_t::draw(SDL_Plotter& g) {
    for(int y = center.y - radius; y <= center.y + radius; y++) {
        
        for(int x = center.x - radius; x <= center.x + radius; x++) {
            
            if (sqrt(pow(center.x - x, 2) + pow(center.y - y, 2)) <= radius) {
                
                if (x >= 0 && y >= 0 && x <= g.getCol() && y <= g.getRow()) {
                    g.plotPixel(x, y, c.R, c.G, c.B);
                }
        }
    }
}
