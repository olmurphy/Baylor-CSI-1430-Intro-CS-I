/*
 Author: Owen Murphy
 Assignment Title: Mixed Data Input
 Assignment Description: Write a program that reads a file, take data from that
    file and sorts the data based on the account number
 Due Date: 10/09/2019
 Date Created: 10/06/2019
 Date Last Modified: 10/09/2019
 */

/*
 Data Abstraction:
    input file stream to open and read data file
    strings to read line one, line two, and the subsequent lines
    output file streams to open each companies files
    input string stream to reach each word of each line
    integer to read account numbers of each line
 Input:
    read in the data file until the file opens
 Process:
    proces each line of the data file and print the line based on the
        guidelines of the account numbers into each companies files
 Output:
    Output each line in data file onto the comapany file that standards of
        account numbers match
 Assumptions:
    It is assumed that the data file exists, else the program will continue
        to run
 
 */


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    // Data Abstraction
    string fileName;
    ifstream dataFile;
    string line_1, line_2;
    ofstream file_A, file_B, file_C;
    string line_N;
    istringstream eachWord;
    int accNum;
    
    
    // Input
    do {
        cout << "Enter Name of Data File: ";
        cin >> fileName;
        cout << fileName << endl;
    
        dataFile.open(fileName.c_str());
        if (!dataFile.is_open()) {
            cout << "Error: File Not Open." << endl;
        }
        
    } while (!dataFile.is_open());
    
    
    // Process
    getline (dataFile, line_1); // store the first two lines of the files
    getline (dataFile, line_2); // store the first two lines of the files
    
    
    file_A.open("Company_A.txt");
    file_B.open("Company_B.txt");
    file_C.open("Company_C.txt");
    file_A << line_1 << endl << line_2 << endl;
    file_B << line_1 << endl << line_2 << endl;
    file_C << line_1 << endl << line_2 << endl;
    
    while (getline (dataFile, line_N)) {
        eachWord.clear();
        eachWord.str(line_N);
        eachWord >> accNum;
        
        if ((accNum >= 0) && (accNum < 100)) {
            file_A << line_N << endl;
        }
        else if ((accNum >= 200) && (accNum < 300)) {
            file_C << line_N << endl;
        }
        else if ((accNum >= 300) && (accNum < 400)) {
            file_B << line_N << endl;
        }
    }
    file_A.close();
    file_B.close();
    file_C.close();
    dataFile.close();

    return 0;
}
