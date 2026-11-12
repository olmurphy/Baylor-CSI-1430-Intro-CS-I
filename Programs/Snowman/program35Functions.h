/*
Author: Owen Murphy
Assignment Title: Snowman
Assignment Description: Write a program that reads in data from a file
   stores data into the array of snowman objects and reports the data members
   along with the statistical data
Due Date: 12/02/209
Date Created: 11/19/2019
Date Last Modified: 11/25/2019
*/

#ifndef program35Functions_h
#define program35Functions_h

#include <fstream>
#include <ostream>
#include <string>
#include "Snowman.h"
#include <iomanip>
using namespace std;

const int WIDTH = 8;

int readDataFromFile(ifstream&  openFileStream, Snowman data[ ]);

int countHats(Snowman data[ ], const int n);

int countScarves(Snowman data[ ], const int n, const string color) ;

double averageVolume(Snowman data[ ], const int n);

void sortSnowmanByScarfColor(Snowman data[ ], const int n);

void sortSnowmanByTemperature(Snowman data[ ], const int n);

void displaySnowman(Snowman data[ ], const int n, ostream&);


#endif /* program35Functions_h */
