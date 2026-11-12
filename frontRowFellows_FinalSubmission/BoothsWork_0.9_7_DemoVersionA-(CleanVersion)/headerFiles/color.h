#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct color_t{
    int R, G, B;

    color_t(){
        R = G = B = 0;

    }
    color_t(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }
    color_t(const color_t& color){
        R = color.R;
        G = color.G;
        B = color.B;
    }
};

const color_t RED(220, 0, 0);
const color_t BLACK(0, 0, 0);
const color_t BLUE(0, 0, 220);
const color_t BLUE_L(86, 249, 255);
const color_t GREEN(0, 220, 0);
const color_t ORANGE (255, 100,0);
const color_t GOLD (212, 175, 55);
const color_t YELLOW(200,200,0);
const color_t SILVER(75,75,75);
const color_t WEISS(255,255,255);
const color_t DARKGREY(132, 132, 132);
const color_t LIGHTGREY(166, 166, 166);
const color_t SKIN1(246, 198, 190);
const color_t SKIN2(187, 140, 133);
const color_t PINK(210, 92, 152);

#endif // COLOR_H_INCLUDED
