//
//  Line.cpp
//  Object notes
//
//  Created by Owen Murphy on 11/11/19.
//  Copyright © 2019 Owen Murphy. All rights reserved.
//

#include "Line.h"

line::line(point a, point b, color col) {
    p1 = a;
    p2 = b;
    c  = col;
}

void line::setPointOne(const point p) {
    p1 = p;
}
void line::setPointTwo(const point p) {
    p2 = p;
}
void line::setColor(const color col) {
    c = col;
}

point line::getPointOne() const {
    return p1;
}
point line::getPointTwo() const {
    return p2;
}
color line::getColor() const {
    return c;
}



bool line::slope(double& m) const {
    bool hasSlope = false;
    hasSlope = p1.x != p2.x;
    if(hasSlope) {
        m = static_cast<double>((p1.y - p2.y)) / (p1.x - p2.x);
    }
    
    return hasSlope;
}
double line::y_interecept() const {
    // y = mx + b
    // b = y - mx
    double m, b;
    if (slope(m)) {
        b = p1.y - m * p1.x;
    }
    
    return b;
}
void line::display(ostream& os) {
    // y = mx + b
    double m, b;
    if(slope(m)) {
        b = y_interecept();
        os << "y = " << m << "x + " << b;
    }
    else {
        os << "x = " << p1.x;
    }
    
}

void line::draw(SDL_Plotter& g) {
    double m, b, y;
    if (slope(m)) {
        b = y_interecept();
        for (int x = min(p1.x, p2.x); x <= max(p1.x, p2.x); x++) {
            y = m * x + b;
            g.plotPixel(x, y, c.R, c.G, c.B);
        }
    }
}
