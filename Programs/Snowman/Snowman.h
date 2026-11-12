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

#ifndef Snowman_h
#define Snowman_h

#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class Snowman
{

     private:
        // Data Members
        double height;
        double weight;
        double temperature;
        bool   hasHat;
        string scarfColor;


     public:
        Snowman ( );  //default constructor
        Snowman(double , double , double , bool , string);
        void setHeight(double );
        void setWeight(double );
        void setTemperature(double );
        void setHasHat(bool );
        void setScarfColor(string);

        double getHeight( );
        double getWeight( );
        double getTemperature( );
        bool   getHasHat( );
        string getScarfColor( );

        double Volume( );
};


#endif /* Snowman_h */
