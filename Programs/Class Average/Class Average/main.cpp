/*
 Author: Owen Murphy
 Assignment Title: Class Average
 Assignment Description: Write a program that read files, and reads other file
    using the data in the initial file and reports averages
 Due Date: 10/07/2019
 Date Created: 10/05/2019
 Date Last Modified: 10/07/2019
 */

/*
 Data Abstraction:
    ifstreams declared - file name and student file - to open files
    string names to find the name file and to output the full name
    multiple integers and double to find statistical data
 Input:
    read in file name, then find the file name of each person using
        format and read in integers
 Process:
    find the file name of each person by concatenating the names
        in the format of the file
    read in numbers and process the numbers to find sum and count to find
        average
 Output:
    output the students name plus the average
    report class average, min and the max
 Assumptions:
    Is is assumed that the files of each student are in the same directory
        else the program would not output anything
    
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    string fileName;
    ifstream dataFile;
    string name;
    istringstream nameSeparated;
    string lastName, firstName, midInit;
    string fullName;
    ifstream studentFile;
    int num;
    double totalCount = 0, totalSum = 0;
    int studentSum, studentCount;
    int min, max;
    double studentAverage, classAverage;
    
    cout << "Enter Name of Data File: ";
    cin >> fileName;
    cout << fileName;
    
    dataFile.open(fileName);
    if(!dataFile.is_open()) {
        cout << "ERROR: File Not Open." << endl;
        exit(1);
    }
    cout << endl << endl;
    cout << setw(25) << left << "Student" << "Average" << endl;
    cout << fixed << setprecision(2);
    
    
    while(getline(dataFile, name)) {
        nameSeparated.clear();
        nameSeparated.str(name);
        nameSeparated >> lastName >> firstName >> midInit;
        fullName = firstName + lastName + ".dat";
        studentFile.open(fullName);
        fullName = firstName + " " + midInit + " " + lastName;
        cout << setw(25) << left << fullName;
        
        if (studentFile.is_open()) {
            studentCount = 0;
            studentSum = 0;
            if(studentFile >> num) {
                do {
                    studentCount++;
                    studentSum += num;
                    totalCount++;
                    totalSum += num;
                    if(totalCount == 1) {
                        min = max = num;
                    }
                    if(max < num) {
                        max = num;
                    }
                    if(min > num) {
                        min = num;
                    }
                } while(studentFile >> num);
                studentAverage = static_cast<double>(studentSum) / studentCount;
                cout << studentAverage << endl;
            }
            else {
                cout << "No Grades" << endl;
            }
        }
        else {
            cout << "No Data File" << endl;
        }
        studentFile.close();
    }
    cout << endl;
    classAverage = static_cast<double>(totalSum) / totalCount;
    cout << "Class Average: " << classAverage << endl;;
    cout << "Max Score: " << static_cast<float>(max) << endl;
    cout << "Min Score: " << static_cast<float>(min) << endl;
    
    cout << endl;
    dataFile.close();
     
    
    // Extra Credit
    double standDev;
    totalSum = 0;
    
    // Class Standard Deviation  = 14.86
    dataFile.open(fileName);
    if (dataFile) {
        
        while(getline(dataFile, name)) {
            nameSeparated.clear();
            nameSeparated.str(name);
            nameSeparated >> lastName >> firstName >> midInit;
            fullName = firstName + lastName + ".dat";
            studentFile.open(fullName);
        
            if (studentFile.is_open()) {
                if (studentFile >> num) {
                    do {
                        totalSum += pow((num - classAverage), 2);
                        
                    } while(studentFile >> num);
                }
            studentFile.close();
            }
            standDev = sqrt(totalSum / totalCount);
        }
        cout << "*** Start Extra Credit ***" << endl << endl;
        
        cout << "Class Standard Deviation  = " << standDev << endl;
        
        cout << endl << "*** End Extra Credit ***" << endl;
    }
    
    dataFile.close();

    
     
    return 0;
}
