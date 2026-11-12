

#ifndef circle_h
#define circle_h

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"

class circle_t {
private:
    double radius;
    point  center;
    color  c;
    
public:
    circle_t(); // default constructor
    circle_t(double, point, color); // custom constructor
    circle_t(const circle_t&); // copy constructor
    // ALWAYS REMEMBER THIS!!!
    
    void setRadius(double);
    void setCenter(point);
    void setColor(color);
    
    double getRadius() const;
    point getCenter() const;
    color getColor() const;
    
    void draw(SDL_Plotter&);
};



#endif /* circle_h */
