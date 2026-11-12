/*
Author: Owen Murphy
Assignment Title: Closest Pair
Assignment Description: Write a program that find the closes pair of points
   given an array of point objects
Due Date: 11/20/2019
Date Created: 11/17/2019
Date Last Modified: 11/20/2019
*/

#include "ClosestPair.h"


Pair Closest_Pair( Point  P[ ], int n) {
    int i, j;
    double ave1, ave2;
    double smallestDistance, distance;
    Pair p;
    
    // set index 1 and index two to the first two points respectively
    p.indexPointOne = 0;
    p.indexPointTwo = 1;
    
    // set it to the first set of points then compare from there
    smallestDistance =  sqrt(pow(P[0].x - P[1].x, 2) +
                             pow(P[0].y - P[1].y, 2));
    
    for (i = 0; i < n - 1; ++i) {
    
        for (j = i + 1; j < n; ++j) {
            distance =  sqrt(pow(P[j].x - P[i].x, 2) +
                             pow(P[j].y - P[i].y, 2));
            
            // compare each point with the smallest distance of points
            // and if the distance currently is smaller, set the two indices
            // to the current indices
            if (distance < smallestDistance) {
                smallestDistance = distance;
                p.indexPointOne = i;
                p.indexPointTwo = j;
            }
            // if the distance is equal set it to the smallest average of the
            // two indices
            else if (distance == smallestDistance) {
                ave1 = (i + j) / 2.0;
                ave2 = (p.indexPointOne + p.indexPointTwo) / 2.0;
                if(ave1 < ave2) {
                    p.indexPointOne = i;
                    p.indexPointTwo = j;
                }
                
            }
        }
    }
    return p;
}
