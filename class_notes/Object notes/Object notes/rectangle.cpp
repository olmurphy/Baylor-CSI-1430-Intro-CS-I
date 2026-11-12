

#include "rectangle.h"

rectangle_t::rectangle_t() {
    upperLeft.x = 0;
    upperLeft.y = 0;
    lowerRight.x = 1;
    lowerRight.y = 1;
    c = RED;
}

rectangle_t::rectangle_t(point ul, point lr, color col) { // do not repeat the default
    upperLeft = ul;
    lowerRight = lr;
    c = col;
}

rectangle_t::rectangle_t(const rectangle_t& other) {
    upperLeft = other.upperLeft;
    lowerRight = other.lowerRight;
    c = other.c;
}


void rectangle_t::setUpperLeft(const point p) {
    upperLeft = p;
}

void rectangle_t::setLowerRight(const point p) {
    lowerRight = p;
}

void rectangle_t::setColor(const color a) {
    c = a;
}


point rectangle_t::getUpperLeft() const {
    return upperLeft;
}

point rectangle_t::getLowerRight() const {
    return lowerRight;
}

color rectangle_t::getColor() const {
    return c;
}

void rectangle_t::draw(SDL_Plotter& g) const {
    // two for loops means it is quadratic in complexity
    for (int y = min(upperLeft.y, lowerRight.y); y <= max(upperLeft.y, lowerRight.y); y++) {
        for (int x = min(upperLeft.x, lowerRight.x); x <= max(upperLeft.x, lowerRight.x); x++) {
            g.plotPixel(x, y, c.R, c.G, c.B);
        }
    }
}
