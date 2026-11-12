/*
 Author: Owen Murphy
 Assignment Title: Mad Libs
 Assignment Description: Write a program that reads a text file
    and everytime there is a place for a works beginning with an
    asterik then have the user input a work and that word becomes the new
    work in the file. Finally print each updated line onto the screen
 Due Date: 10/11/2019
 Date Created: 10/07/2019
 Date Last Modified: 10/11/2019
 */

/*
 Data Abstraction:
    Declare vairables as string, file to read file name, line to store the
        current line and word to read each word on line
    Declare input file stream to read in the text file
    Declare input string stream to put the line into stream and output string
        stream to store each updated word for later output
    Integer count to count times to open file
 Input:
    Read in the file name and continue trying if fail for the three times. If
        after three times and file is not open print error and exit the program
 Process:
    Read in each line using input string stream in while loop and read in each
        word into a string. If the string starts with an asterik, drop the
        asterik and ask the user to input a part of speech specified word.
    Read in the new work or if no asterik read in that word to the string
        stream.
    Finally, update line with the new words
 Output:
    Output each line after reading each word
 Assumptions:
    It is assuemed the user enters a valid word that is a string.
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    
    int count = 0;
    string fileName;
    ifstream textFile;
    string line, word;
    istringstream readLine;
    ostringstream newLine;
    
    do {
        cout << "Enter file name: ";
        cin >> fileName;
        cout << fileName << endl;
        count++;
        textFile.open(fileName);
        
    } while (!textFile && count < 3);
    
    if (!textFile && count == 3) {
        cout << "Error: File Failed to open after 3 tries." << endl;
        exit(1);
    }
    
    while(getline(textFile, line)) {
        readLine.clear();
        readLine.str(line);
        while (readLine >> word) {
            if (word.at(0) == '*') {
                word.erase(word.begin());
                cout << "Please enter a " << word << ": ";
                cin >> word;
                cout << word << endl;
                newLine << word << " ";
            } else {
                newLine << word << " ";
            }
        }
        newLine << endl;
    }
    
    cout << endl << endl << newLine.str();
    textFile.close();
    
    return 0;
}
