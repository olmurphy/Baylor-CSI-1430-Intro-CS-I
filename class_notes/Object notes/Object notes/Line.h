//
//  Line.h
//  Object notes
//
//  Created by Owen Murphy on 11/11/19.
//  Copyright © 2019 Owen Murphy. All rights reserved.
//

#ifndef Line_h
#define Line_h

#include "point.h"
#include "color.h"
#include <cassert>
using namespace std;


class line {
private:
    point p1, p2;
    color c;
    
public:
    // line();
    line(point = point (0,0), point = point (1,1), color = BLACK);
    bool slope(double& m) const;
    double y_interecept() const;
    void display(ostream&);
    void draw(SDL_Plotter&);
    
    void setPointOne(const point);
    void setPointTwo(const point);
    void setColor(const color);
    
    point getPointOne() const; // function may not change interanl data
    point getPointTwo() const; // const function will not call another
    color getColor() const;    // that breaks the rule of const funct
    
};

#endif /* Line_h */
