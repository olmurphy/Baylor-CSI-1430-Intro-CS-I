#ifndef rectangle_h
#define rectangle_h

#include "point.h"
#include "color.h"
#include "SDL_Plotter"

class rectangle_t {
private:
    point upperLeft, lowerRight;
    color c;
    
public:
    rectangle_t();
    rectangle_t(point, point, color = RED);
    rectangle_t(const rectangle_t&);
    
    void setUpperLeft(const point);
    void setLowerRight(const point);
    void setColor(const color);
    
    point getUpperLeft() const;
    point getLowerRight() const;
    color getColor() const;
    
    void draw(SDL_Plotter& g) const;
    
    
};



#endif /* rectangle_h */
