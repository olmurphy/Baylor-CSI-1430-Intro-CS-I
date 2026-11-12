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

#include "program35Functions.h"
#include "Snowman.h"

/*
 Description:
    function that reads data from a file storing the input data in the snowman
        object array
 Return:
    integer return type, returns an interger of the number of snowman read
        into
 Precondition:
    a pass by reference input file stream is passed in along with an snowman
        object array that is automatically pass by reference
    the values exists
 Postcondition:
    the values of all the data members are mutated to the values read in from
        the file
 */
int readDataFromFile(ifstream& openFileStream, Snowman data[ ]) {
    int numSnowman = 0;
    double height, weight, temp;
    bool hat;
    string col;
    
    while (openFileStream >> height >> weight >> temp >> hat >> col) {
        data[numSnowman].setHeight(height);
        data[numSnowman].setWeight(weight);
        data[numSnowman].setTemperature(temp);
        data[numSnowman].setHasHat(hat);
        data[numSnowman].setScarfColor(col);
        
        numSnowman++;
    }
    
    return numSnowman;
}

/*
Description:
    function that calculates the total number of hats and returns the result
Return:
    returns an integer of total number of hats
Precondition:
    array of snowman object is passed in along with a constant integers n
        indicating the size of the array
    the values exist
Postcondition:
    the values are unchanged and the number of hats is returned
*/
int countHats(Snowman data[ ], const int n) {
    int numHats = 0;
    
    for (int i = 0; i < n; ++i) {
        if (data[i].getHasHat()) {
            numHats++;
        }
    }
    
    return numHats;
}

/*
Description:
    Function that counts the number of scarves that are the indicated color
Return:
    returns the number of scars that are the color passed in
Precondition:
    snowman object array is passed in along with a constant integer n
        representing the size of the array
    the string color is passed in to compare the color
Postcondition:
    the values are unchanged and the number of the color scarves are returned
*/
int countScarves(Snowman data[ ], const int n, const string color) {
    int countScarves = 0;
    
    for (int i = 0; i < n; ++i) {
        
        if (data[i].getScarfColor() == color) {
            countScarves++;
        }
        
    }
    
    return countScarves;
}

/*
Description:
    function caculates the average volume of each snowman by calling the
        volume method from snowman class and sum and dividing by number of
        snowman
Return:
    returns the average number of snowman of type double
Precondition:
    takes in an array of snowman object along with a constant integer n
        representing the size of array
Postcondition:
    the values are unchanged and the average volume is returned
*/
double averageVolume(Snowman data[ ], const int n) {
    double sumVolume = 0;

    for (int i = 0; i < n; ++i) {
        sumVolume += data[i].Volume();
    }
    
    return sumVolume / n;
}

/*
Description:
    the function sorts the snowman object array by color in alphabetical order
Return:
    void return type, does not return anything
Precondition:
    takes in an object array of snowman and a constant integer n that represent
        the size of array
    the value exists
Postcondition:
    the values are unchanged but the order is changed
 
*/
void sortSnowmanByScarfColor(Snowman data[ ], const int n) {
    
    for (int pass = 0; pass < n - 1; pass++) {
        
        for (int j = 0; j < n - 1; j++) {
            
            if (data[j].getScarfColor() > data[j + 1].getScarfColor()) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

/*
Description:
    the function sorts the object array of snowman by temperature
Return:
    void return type, does not return anything
Precondition:
    array of snowman object is passed in and the constant integer n represents
        the size of the array
    the values exist
Postcondition:
    the values are unchanged by the order is changed if unsorted
*/
void sortSnowmanByTemperature(Snowman data[ ], const int n) {
    
    for (int pass = 0; pass < n - 1; pass++) {
        
        for (int j = 0; j < n - 1; j++) {
            
            if (data[j].getTemperature() > data[j + 1].getTemperature()) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

/*
Description:
    function displays the data members in the format as indicated on the
        upload site
Return:
    void type return, does not return anything
Precondition:
    takes in an array of snowman objects, a constant integer n representing
        the size of the array and a pass by reference ostream for outputting
    the values exist
Postcondition:
    the values are unchanged
    
*/
void displaySnowman(Snowman data[ ], const int n, ostream& os) {
    os << fixed << setprecision(2);
    
    for (int i = 0; i < n; ++i) {
        os << setw(WIDTH) << data[i].getHeight()
           << setw(WIDTH) << data[i].getWeight()
           << setw(WIDTH) << data[i].getTemperature()
           << setw(WIDTH);
        
        if (data[i].getHasHat()) {
            os << "yes";
        }
        else {
            os << "no";
        }
        os << setw(WIDTH) << data[i].getScarfColor()
           << endl;
    }
}
