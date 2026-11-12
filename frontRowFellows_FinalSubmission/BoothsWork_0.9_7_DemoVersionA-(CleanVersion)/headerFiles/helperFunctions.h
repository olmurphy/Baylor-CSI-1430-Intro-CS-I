#ifndef HELPERFUNCTIONS_H_INCLUDED
#define HELPERFUNCTIONS_H_INCLUDED

#include "SDL_Plotter.h"
#include "Enemy.h"
#include "color.h"
#include "Bullet.h"
#include "Booth.h"

#include <ctime>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/*
Description:
    sets the coordinate of each enemy in the array
Return:
    void return type
Precondition:
    takes in an array of Enemy objects, constant integer eL, constant integer eW
        and a color_t object color as parameters
    the values exist
Postcondition:
    the array of enemies is filled with coordinates

*/
void enemySet(Enemy data[ ], const int eL, const int eW,  color_t color);

/*
Description:
    sets the enemy points in the final battle
Return:
    void return type
Precondition:
    takes in an array of enemy objects and a constant integer n
Postcondition:
    values of enemy array are set to their respective points
*/
void enemySet2(Enemy data[ ], const int n);

/*
Description:
    draws the enemies on SDL plotter
Return:
    void return type
Precondition:
    takes in an array of enemy objects, constant integer eL, constant integer eW
        integer, and a two dimensional array of 15x15
Postcondition:
    values are changed to their respective sprites
*/
void enemyDraw(SDL_Plotter&, Enemy [ ], const int eL, const int eW, int, int spriteT[][15]);

/*
Description:
    draws the enemies for the boss
Return:
    void return type
Precondition:
    takes in an array of enemy objects, SDL plotter pass by reference, constant integer eL,
        constant integer eW, integer, and a 2 dimensional array spriteT
    values exist
Postcondition:
    values are drawn with thier respective sprites

*/
void enemyDraw2(SDL_Plotter&, Enemy [ ], const int eL, const int eW, int, int spriteT[][15]);

/*
Description:
    sets the background for the SDL
Return:
    void return type
Precondition:
    takes in the SDL screen, 2 constant integer
Postcondition:
    values of SDL color are changed to black
*/
void setBack(SDL_Plotter&, const int, const int);

/*
Description:
    shifts the enemies points to the left
Return:
    void return type
Precondition:
    takes in an array of enemy objects, constant integer eL, constant integer eW
    values exist
Postcondition:
    values of enemy objects' points are shifted to the left
*/
void moveLeft(Enemy data[ ], const int eL, const int eW);

/*
Description:
    moves the enemies points to the right
Return:
    void return type
Precondition:
    takes in an array of enemy objects, constant integer eL, constant integer eW
    values exist
Postcondition:
    values or the enemies are moved to the right
*/
void moveRight(Enemy data[ ], const int eL, const int eW);

/*
Description:
    moves the enemies points down the screen
Return:
    void return type
Precondition:
    takes in an array of enemy objects, constant integer eL, constant ineger eW
Postcondition:
    values are of each enemies points are moved down the screen
*/
void moveDown(Enemy data[ ], const int eL, const int eW);

/*
Description:
    shifts the array of enemy objects in the motion of space invaders
Return:
    void return type
Precondition:
    takes in an array of enemy objects, constant integer eL, constant integer eW
        pass by reference integer murder
    the values exist
Postcondition:
    values are changed with each function call
*/
void moveCycle(Enemy data[ ], const int eL, const int eW, int& murder);

/*
Description:
    moves the array of enemy objects in the final battle
Return:
    void return type
Precondition:
    takes in an array of enemy objects, pass by reference the object booth, constant integer n
        and pass by reference murder
Postcondition:
    the values of the enemy objects and booth objects' points are shifted on the function calls
*/
void moveCycle2(Enemy data[ ], Booth_t&, const int n, int& murder);

/*
Description:
    sets the point of the bullet
Return:
    void return type
Precondition:
    takes in an array of bullet, constant integer n, and a ship object
Postcondition:
    the values of bullet objects' points are changed
*/
void bulletSet(Bullet data[ ], const int n, Ship);

/*
Description:
    draws the bullets on the screen
Return:
    void return type
Precondition:
    takes in an array of bullet objects, constant integer n and a SDL plotter
Postcondition:
    values of the bullet object are drawn on the screen
*/
void bulletDraw(SDL_Plotter&, Bullet [ ], const int n);

/*
Description:
    moves the bullets points up at the enemies
Return:
    void return type
Precondition:
    takes in an array of bullet objects, constant integer n
Postcondition:
    values of the bullet objects' points are changed

*/
void moveBullet(Bullet data[ ], const int n);

/*
Description:
Return:
    void return type
Precondition:
Postcondition:
*/
bool bulletHit(Bullet data1[ ], const int n1, Enemy data2[ ], const int n2, Mix_Chunk*);

/*
Description:
    selects random enemy
Return:
    int index ship
Precondition:
    enemy is alive
Postcondition:
    enemy is unchanged
*/
int randShipSelect(const int n);

/*
Description:
    sets the upper left point of the bullet from enemy
Return:
    void return type
Precondition:
    enemy is alive
    bullet is available
Postcondition:
    bullet is not available
    bullet is sent to move funct
*/
void enemyBulletSet(Bullet data[ ], const int n, Enemy, Mix_Chunk*);

/*
Description:
    moves enemy bullets
Return:
    void return type
Precondition:
    bullet isn't available
Postcondition:
    bullet is moved
*/
void moveEnemyBullet(Bullet data[ ], const int n, const int s);

/*
Description:
    checks if enemy bullet hits ship
Return:
    void return type
Precondition:
    ship has lives
    bullet isn't available
Postcondition:
    ship looses life if hit
    bullet disappears if hit
*/
void enemyBulletHit(Bullet data[ ], const int n1, Ship&, int&, int&);

/*
Description:
    sets life bullet positions
Return:
    void return type
Precondition:
    ship has lives
Postcondition:
*/
void lifeBulletSet(Bullet data[ ], const int n);

/*
Description:
    checks the position of the enemies if they hit the bottom
Return:
    returns a boolean value type
Precondition:
    takes in an array of enemy objects, constant integer and a pass by reference boolean value
Postcondition:
    values are unchanged
*/
bool checkEnemyPos(Enemy [], const int, bool&);

/*
Description:
    draws the laser of booth on the screen
Return:
    void return type
Precondition:
    takes in the SDL screen, boolean, object Booth_t, and an array of
        bullet objects
Postcondition:
    values are unchanged and the laser is drawn on the screen
*/
void drawLaser(SDL_Plotter& alfa, bool, Booth_t, Bullet bullet[]);

/*
Description:
    checks if the laser hits the ship
Return:
    returns a boolean value
Precondition:
    takes in an array of bullet objects, constant integer n1, and a
        pass by reference booth_t object
Postcondition:
    values are unchanged
*/
bool boothHit(Bullet data1[ ], const int n1, Booth_t& bill);

/*
Description:
    sets the laser point of booths laser
Return:
    void return type
Precondition:
    takes in an array of bullet objects, and a constant integer n
Postcondition:
    values of the bullet objects are set
*/
void boothBulletSet(Bullet data[ ], const int n);

/*
Description:
    draws booths head in the SDL plotter
Return:
    void return type
Precondition:
    takes in the SDL plotter screen, and a booth_t object
        and a boolean value
Postcondition:
    values are unchanged and the head is drawn

*/
void drawBooth(SDL_Plotter&, Booth_t, bool);
#endif // HELPERFUNCTIONS_H_INCLUDED
