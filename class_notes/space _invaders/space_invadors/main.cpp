#include <iostream>


const int cannonRow = 10;
const int cannonCol = 15;

int main() {
    // have the cannon mover wherever
    
    SDL_PLOTTER g(500, 500);
    char key;
    
    int speed = 1;
    int cannonX = g.getCol()/2;
    int cannonY = g.getRow()/2;
    int cannon[cannonRow][cannonCol] =
                       {
                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}
                       };
     
     while (!g.getQuit()) {
        if (g.kbhit()) {
            key = g.getKey();
            // erase the cannon
            for (int r = 0; r < cannonRow; r++) {
                for (int c = 0; c < cannonCol; c++) {
                    if (cannon[r][c]){
                        g.plotPixel(cannonX (called your offset) + c, cannonY + r, 255, 255, 255);
                    }
                }
            }
            // update the location
            switch(toupper(key)){
                case RIGHT_ARROW: cannonX += speed;
                                  break;
            
                case LEFT_ARROW:  cannonX -= speed;
                                  break;
                    
                case UP_ARROW:    speed ++;
                                  break;
                    
                case DOWN_ARROW:  if (speed > 1) {
                                     speed --;
                                     }
                                  break;
            }
            
            // create the cannon
            for (int r = 0; r < cannonRow; r++) {
                for (int c = 0; c < cannonCol; c++) {
                    if (cannon[r][c]){
                        g.plotPixel(cannonX (called your offset) + c, cannonY + r, 0, 200, 0);
                    }
                }
            }
            
        }
        g.update();
     
     }
    return 0;
}
/*
 same format as last time
 */


int main (int argc, char ** argv)
{
    SDL_PLOTTER g(500, 500);
    char key;
    while (!g.getQuit()) { // master control loop "escape" or set quit to true
        if (g.kbhit()) {
            key = g.getKey();
            switch(key) {
                case UP_ARROW: break;
                default:
                
                    
            }
        }
        
        g.update();
    }
    
    return 0;
}





































































