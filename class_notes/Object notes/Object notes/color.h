
#ifndef color_h
#define color_h


struct color {
    int R, G, B;
    
    color() {
        R = G = B = 0;
    }
    color(int r, int g, int b) {
        R = r;
        G = g;
        B = b;
    }
    
    color(const color& c) {
        R = c.R;
        G = c.G;
        B = c.B;
    }
    
};

const color RED(220, 0, 0);
const color BLACK(0, 0, 0);


#endif /* color_h */
