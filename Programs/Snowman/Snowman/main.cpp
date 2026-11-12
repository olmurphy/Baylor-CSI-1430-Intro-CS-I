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

/*
 Data Abstraction:
    string fileName to store the name of the file
    array of snowman object of size 100 to store the data of file
        into each snowman data member
    ifstream file to open a file stream for reading into
    int numsnowman to store the number of snowman read from file
    int numRedScarves to store the number of snowman with red scarves
    int withHats to store the number of snowmen with hats
 Input:
    read in the name of the data file
    Read in the input from the file while storing input into each
        element of snowman object array
 Process:
    call the function sortSnowmanByScarfColor to sort the array
        of snowman object by scarfs
    call the function sortSnowmanByTemperature to sort the array of snowman
        object by temperature
    call the countScarves function to calculate the number of scare that
        are red
    call the countHats function to calculate the number of hats of all the
        snowman objects
 Output:
    Print the header in the format as indicated on the upload site
    call the displaySnowman function to display the data members of each
        snowman
    Print the numberoof snowman with a red scarf, average volume, and the
        number of hats
 Assumptions:
    It is assumed that all input from read from the data file is valid input
    It is assumed that the file has no more than 100 elements of snowman object
    It is assumed that there is at least one snowman object data to be read
 */

#include <iostream>
#include "Snowman.h"
#include "program35Functions.h"
#include <string>
#include <fstream>

int main() {
    
    // Data Abstraction
    Snowman snowPeople[100];
    string fileName;
    ifstream file;
    int numSnowman;
    int numRedScarves;
    int withHats;
    
    do {
        cout << "Enter Name of Data File: ";
        cin >> fileName;
        cout << fileName << endl;
        
        file.open(fileName);
        
        if (!file) {
            cout << "Error: File Not Open." << endl;
        }
        
    } while (!file);
    
    // User Input
    getline(file, fileName); // skips first two lines of input
    getline(file, fileName); // skips first two lines of input
    
    numSnowman = readDataFromFile(file, snowPeople);
    
    file.close();
    
    // Data Processing
    //sortSnowmanByTemperature(snowPeople, numSnowman);
    sortSnowmanByTemperature(snowPeople, numSnowman);
    sortSnowmanByScarfColor(snowPeople, numSnowman);


    numRedScarves = countScarves(snowPeople, numSnowman, "RED");
    withHats = countHats(snowPeople, numSnowman);
    
    // Output
    cout << setw(WIDTH) << "Height" << setw(WIDTH) << "Weight"
         << setw(WIDTH) << "Temp" << setw(WIDTH) << "Hat"
         << setw(WIDTH) << "Scarf\n" << endl;
    
    displaySnowman(snowPeople, numSnowman, cout);

    cout << endl << setw(4) << left << withHats << "Snowmen have a hat."
         << endl << setw(4) << left << numRedScarves
         << "Snowmen have a RED scarf." << endl
         << "The average volume of a snowman is "
         << averageVolume(snowPeople, numSnowman) << endl;
     
    return 0;
}
