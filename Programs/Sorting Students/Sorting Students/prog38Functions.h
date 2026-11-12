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


#ifndef prog38Functions_h
#define prog38Functions_h

#include <string> // string
#include <ostream> // ostream
#include <fstream> // ifstream
#include <iostream>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    int currClass;
    int zipCode;
    int age;
    string homeTown;
    double gpa;
    
public:
    
    /*
    Description:
       default constructor set defualt values to data memebers
    Return:
       no return type on default constructor
    Precondition:
       the default constructor takes no parameters
    Postcondition:
       the values are set to their default values
    */

    Student(); // default constructor
    
    /*
    Description:
       method that sets the values of the data members to their respective
           values passed in as parameters
    Return:
       void return type
    Precondition:
       the method takes in 3 strings, 2 integers, and a double for the data
       the values exist
    Postcondition:
       the values are mutated to their respective values passed in as parameters
    */
    void setStudent(string, string, int, int, int, string, double);
    
    // Getter functions
    /*
    Description:
       method that returns the first name of the student
    Return:
       returns a string
    Precondition:
       takes in no parameters
    Postcondition:
       the values are unchanged adn the first name is returned
    */
    string getFirstName() const;
    
    /*
    Description:
       the method returns the last name of the objecty
    Return:
       returns a string
    Precondition:
       takes in no parameter values
    Postcondition:
       the values are unchanged and the last name is returned
    */
    string getLastName() const;
    
    /*
    Description:
       the method returns the current classification
    Return:
       returns a string
    Precondition:
       takes in no parameters
    Postcondition:
       the values are unchanged and the currClass is returned
    */
    int getCurrClass() const;
    
    /*
    Description:
       the method returns the zip code
    Return:
       returns an integer
    Precondition:
       takes in no parameters
    Postcondition:
       the values are unchanged and returns the zipCode
    */
    int    getZipCode() const;
    
    /*
    Description:
       the method returns the age
    Return:
       returns an integer
    Precondition:
       takes in no parameters
    Postcondition:
       the values are unchanged and returns the age
    */
    int    getAge() const;
    
    /*
    Description:
       The method returns the name of the hometown for the student object
    Return:
       returns a string
    Precondition:
       takes in no parameters
    Postcondition:
       the values are unchanged and returns the homeTown
    */
    string getHomeTown() const;
    
    /*
    Description:
       method returns the gpa of the student object
    Return:
       returns a double
    Precondition:
       takes in no parameters
    Postcondition:
       the values are unchanged and returns the gpa
    */
    double getGPA() const;
    
    
};

/*
 Description:
    function that returns the string version of the integers 0 - 3;
        reprenting the classification of each student
 Return:
    retuns a string
 Precondition:
    takes in an array of student objects and a constant integer n representing
        the index of the array of objects
    the value exists
 Postcondition:
    the values are unchanged and the string version of classification is
        returned
 */
string returnTheClass(Student data[], const int n);

/*
Description:
   the function reads the data into the array of student objects passed in
   returns the number of students objects read into
Return:
   returns an integer
Precondition:
   the function takes in a pass by reference ifstream to to read data into
   takes in an array of student objects
   the values exist
Postcondition:
   the values of the array of student object is set to the values read in from
       the file
*/
int readStudentData(ifstream&, Student data[]);

/*
Description:
   function displays the header of the report
Return:
   void return type
Precondition:
   the function takes in a pass by reference ostream to intsert the header in
   the value exists
Postcondition:
   the ostream os is inserted the header output
*/
void displayHeader(ostream&);

/*
Description:
   the function sorts the array of students obects by their first name
Return:
   void return type
Precondition:
   the function takes in an arrry of student objects, and an integer n
       representing the number of students
Postcondition:
   the values are unchanged only the position at which they lie in the array
       are changed
*/
void sortByFirstName(Student data[], int n);

/*
Description:
   Functions sorts the array of student objects by their last name data mmeber
Return:
   void return type
Precondition:
   takes in an array of students objects, an integer representing the number
       of students objects
   the values exist
Postcondition:
   the values are unchanged but the order is changed
*/
void sortByLastName(Student data[], int n);

/*
Description:
   function that sorts the array of student objects by their current
       classification
Return:
   void return type
Precondition:
   takes in array of student objects and an integer n representing the number
       of students in the array
Postcondition:
   the values are unchanged but their order is changed if they are out of
       order
*/
void sortByClassification(Student data[], int n);

/*
Description:
   function displays the report of all the students in the order requested in
       the assignment details
   if the record have the same first name, last name, gpa, and classification
       then a warning message is printed instead
Return:
   void return type
Precondition:
   takes in pass by reference ostream, an array of student objects, and an
       integer representing the number of students in the array
Postcondition:
   the values are unchanged and the
*/
void sortByGPA(Student data[], int n);

/*
Description:
   function that sorts the array of students by their GPA
Return:
   void return type
Precondition:
   takes in an array of student objects and an integer representing the size
       of the array
Postcondition:
   values are unchanged and the order is changed if they are out of order
*/
void displayStudents(ostream&, Student data[], int n);



// Extra credit functions
/*
 Description:
    function calculates and returns the gpa of the whole freshmen class
 Return:
    returns a double value
 Precondition:
    takes in an array of student object and a constant integer n reperesenting
        the number of students in the array
    values exist
 Postcondition:
    values are unchanged and the average freshmen gpa is returned
 */
double AverageFreshmenGPA(Student data[], const int n);

/*
 Description:
    function calculates and returns the gpa of the whole sophomore class
 Return:
    returns a double type values
 Precondition:
    takes in an array of student object and a constant integer n reperesenting
        the number of students in the array
    values exist
 Postcondition:
    values are unchanged and the average gpa of the sophomore class is returned
 */
double AverageSophomoreGPA(Student data[], const int n);

/*
Description:
    function calculates and returns the gpa of the whole junior class
Return:
    returns a double type value
Precondition:
    takes in an array of student object and a constant integer n reperesenting
        the number of students in the array
    values exist
Postcondition:
    values are unchanged the the average gpa of the junior class is returned
*/
double AverageJuniorGPA(Student data[], const int n);


/*
Description:
    function calculates and returns the gpa of the whole senior class
Return:
    returns a double type value
Precondition:
    takes in an array of student object and a constant integer n reperesenting
        the number of students in the array
    values exist
Postcondition:
    values are unchanged the the average gpa of the senior class is returned
*/
double AverageSeniorGPA(Student data[], const int n);


#endif /* prog38Functions_h */
