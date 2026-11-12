/*
 Author: Owen Murphy
 Assignment Title: GPS
 Assignment Description: Write a program that keeps track of the points on the
    cartesian plane the user goes to and record statistical data
 Due Date: 10/02/2019
 Date Created: 10/02/2019
 Date Last Modified: 10/02/2019
 */

/*
 Data Abstraction:
    Declare variables x and y to read the points on the cartesian plane
    distance, bool values start and stop to track if there is a stop and an
        end
    and other x and y variables to track the number specific points on the
        cartesian plane
 Input:
    Read in input from the user, the commands, then the x y coordinates
 Process:
    keep track of the total distance traveled everytime move from one place to
        another
 Output:
    Print to the screen the final position, total position and the distance
        from the starting position
 Assumptions:
    It is assumed that the inputs from the user are valid integers of pair
        following a format of command, then x integer then the y integer
 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    
    // Data Abstraction
    double x, y;
    string command;
    double distance;
    bool start = false;
    bool stop = false;
    double deltaPos;
    double startx, starty, prevx, prevy;
    double aveDistanceTracker;
    double aveSum = 0;
    int count = 0;
    
    
    // Input & Process
    cout << "Please start entering GPS data: " << endl;
    
   do {
       cin >> command >> x >> y;
       if (command == "START") {
            startx = x;
            starty = y;
            distance = 0;
            deltaPos = 0;
            start = true;
            prevx = x;
            prevy = y;
        }
        else if (start) {
            distance += sqrt(pow((x - prevx), 2) + pow((y - prevy), 2));
            
            aveDistanceTracker = sqrt(pow((x - startx), 2) + // Extra Credit
                                      pow((y - starty), 2));
            aveSum += aveDistanceTracker; // Extra Credit
            count++;
            prevx = x;
            prevy = y;
            if ((command == "STOP") && start) {
                deltaPos = sqrt(pow(x - startx, 2) + pow(y - starty, 2));
                stop = true;
            }
        }
       
    } while(!stop);
    
    
    // Output
    if (start && stop) {
        cout << fixed << setprecision(1);
        cout << "Final Location: (" << static_cast<double>(x) << ", "
             << static_cast<double>(y) << ")" << endl;
        cout << "Total distance traveled " << distance << endl;
        cout << "Distance to starting point " << deltaPos << endl;
    }
    
    cout << endl;
    
    cout << "*** Start Extra Credit ***" << endl << endl;

    cout << "Average distance to start point = " << aveSum/count << endl
         << endl;

    cout << "*** End Extra Credit ***" << endl;
    
    return 0;
}
