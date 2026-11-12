#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "point.h"
#include "color.h"
#include "Ship.h"
#include "SDL_Plotter.h"

class Bullet{
private:
    bool isAv;
    point uL;
    color_t color;
    int length;
public:
    Bullet();

    void setAv(const bool a);
    void setUL(const point u);
    void setColor(const color_t c);
    void setLength(const int l);

    bool getAv() const;
    point getUL() const;
    color_t getColor() const;
    int getLength() const;

    void moveBullet();
    void drawBullet(SDL_Plotter&);
};

#endif // BULLET_H_INCLUDED
