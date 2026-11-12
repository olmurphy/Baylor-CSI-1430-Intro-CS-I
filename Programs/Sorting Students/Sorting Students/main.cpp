/*
 Author: Owen Murphy
 Assignment Title: Sorting Students
 Assignment Description: Write a program that stores data of students and
    prints the data of each students in sorted order and if students are the
    same print a warning message instead
 Due Date: 12/06/2019
 Date Created: 11/30/2019
 Date Last Modified: 12/06/2019
 */

/*
 Data Abstraction:
    ifstream to open an input file stream to read into
    array of students objects to hold data in
    integer numStudents to store the number of students read from input
 Input:
    call the function readStudentData to read the data from the file
 Process:
    call the funcitons sortByFirstName, sortByLastName, sortByClassification
        sortByGPA to sort by gpa, sub-sorted by classfication, sub-sorted by
        last name, sub-sorted by firstname
 Output:
    the the records of all the students and if the records are duplicates print
        a warning message
 Assumptions:
    It is assumed that all input is valid data input
 */


#include <iostream>
#include <fstream> // ifstream
#include "prog38Functions.h"
#include <cstdlib> // exit()
#include <iomanip> // fixed setprecision()
using namespace std;

const int SIZE = 100;

int main() {

    // Data Abstraction
    ifstream file;
    Student students[SIZE];
    int numStudents;
    
    file.open("stDATA.txt");
    if (!file) {
        exit(1);
    }
    
    // User Input
    numStudents = readStudentData(file, students);
    
    // Data Processing & Output
    
    // sorted by GPA, sub-sorted by classification, sub-sorted by last name
    // sub-sorted by first name
    sortByFirstName(students, numStudents);
    sortByLastName(students, numStudents);
    sortByClassification(students, numStudents);
    sortByGPA(students, numStudents);
    
    displayHeader(cout);
    displayStudents(cout, students, numStudents);
    
    cout << "\n\n*** Start Extra Credit *** \n\n";

    // Extra credit output
    
    cout << "Freshman average GPA = "
         << AverageFreshmenGPA(students, numStudents) << endl
         << "Sophomore average GPA = "
         << AverageSophomoreGPA(students, numStudents) << endl  // 3.13
         << "Junior average GPA = "
         << AverageJuniorGPA(students, numStudents) << endl     //2.81
         << "Senior average GPA = "
         << AverageSeniorGPA(students, numStudents) << endl;  //2.98

    cout << "\n*** End Extra Credit ***\n";

    
    
    return 0;
}
