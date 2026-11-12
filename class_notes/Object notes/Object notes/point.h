/*
 doc header, put name
 */

#ifndef point_h
#define point_h

#include <ostream>
#include <cmath>
#include "color.h"
using namespace std;



struct point { // everythign is public in struct
public:
    int x, y;
    color c;
    point();
    point(int, int);
    point(const point&);
    void display(ostream&);
    
    double distance (point);
    
};


#endif /* point_h */


/*
 
 add sdl .cpp and .h of SDL
 */
