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



#include <iomanip> // setw()
#include "prog38Functions.h"


Student::Student() {
    firstName = "First Name";
    lastName = "Last Name";
    currClass = -1;
    zipCode = 00000;
    age = 0;
    homeTown = "Texas";
    gpa = 4.0;
}

void Student::setStudent(string first, string last, int classification,
                         int zip, int age, string home, double gpa)
{
    firstName = first;
    lastName = last;
    currClass = classification;
    zipCode = zip;
    this->age = age;
    homeTown = home;
    this->gpa = gpa;
    
}


string Student::getFirstName() const {
    return firstName;
}


string Student::getLastName() const {
    return lastName;
}


int Student::getCurrClass() const {
    return currClass;
}


int Student::getZipCode() const {
    return zipCode;
}


int Student::getAge() const {
    return age;
}


string Student::getHomeTown() const {
    return homeTown;
}


double Student::getGPA() const {
    return gpa;
}


int readStudentData(ifstream& openFileStream, Student data[]) {
    int numStudents = 0;
    string first, last, classification, home;
    int zip, age, classNumber;
    double gpa;
    
    getline(openFileStream, first); // skips the first line of the data file
    while (openFileStream >> first >> last >> classification >> zip >> age
           >> home >> gpa)
    {
        // FR = 0, SO = 1, JR = 2, SR = 3
        if (classification == "FR") {
            classNumber = 0;
        }
        else if (classification == "SO") {
            classNumber = 1;
        }
        else if (classification == "JR") {
            classNumber = 2;
        }
        else {
            classNumber = 3;
        }
        
        
        data[numStudents].setStudent(first, last, classNumber, zip, age,
                                     home, gpa);
        numStudents ++;
    }
    
    return numStudents;
}

void sortByFirstName(Student data[], int n) {
    
    for (int pass = 0; pass < n - 1; pass++) {
    
        for (int j = 0; j < n - 1 - pass; j++) {
            
            if (data[j].getFirstName() > data[j + 1].getFirstName()) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void sortByLastName(Student data[], int n) {
    
    for (int pass = 0; pass < n - 1; pass ++) {
        
        for (int j = 0; j < n - 1 - pass; j++) {
            
            if (data[j].getLastName() > data[j + 1].getLastName()) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void sortByClassification(Student data[], int n) {
    
    for (int pass = 0; pass < n - 1; pass++) {
        
        for (int i = 0; i < n - 1 - pass; i++) {
            
            if (data[i].getCurrClass() > data[i + 1].getCurrClass()) {
                swap(data[i], data[i + 1]);
            }
        }
    }
}

void sortByGPA(Student data[], int n) {
    
    for (int pass = 0; pass < n - 1; pass++) {
        
        for (int i = 0; i < n - 1 - pass; i ++) {
            
            if (data[i].getGPA() > data[i + 1].getGPA()) {
                swap(data[i], data[i + 1]);
            }
        }
    }
}

string returnTheClass(Student data[], const int n) {
    string classification;
    
    if (data[n].getCurrClass() == 0) {
        classification = "FR";
    }
    else if (data[n].getCurrClass() == 1) {
        classification = "SO";
    }
    else if (data[n].getCurrClass() == 2) {
        classification = "JR";
    }
    else {
        classification = "SR";
    }
    
    return classification;
}

void displayHeader(ostream& os) {
    os << setw(20) << left << "First Name" << setw(20) << left << "Last Name"
       << setw(10) << left << "Class"      << setw(10) << left << "Zip"
       << setw(10) << left << "Age"        << setw(25) << left << "HomeTown"
       << "GPA\n"    << endl;
}

void displayStudents(ostream& os, Student data[], int n) {
    
    for (int i = 0; i < n; i++) {
        bool duplicateRecord = false;
        int numDuplicates;
        
        os << setw(20) << left << data[i].getFirstName()
           << setw(20) << data[i].getLastName()
           << setw(10) << returnTheClass(data, i)
           << setw(10) << data[i].getZipCode()
           << setw(10) << data[i].getAge()
           << setw(25) << data[i].getHomeTown()
           << fixed << setprecision(2) << data[i].getGPA() << endl;
        
        // skips the next duplicate records
        numDuplicates = 0;
        while (data[i].getFirstName() == data[i + 1].getFirstName() && // first
        data[i].getLastName()         == data[i + 1].getLastName() &&  // last
        data[i].getGPA()              == data[i + 1].getGPA() &&       // gpa
        data[i].getCurrClass()        == data[i + 1].getCurrClass())   // class
        {
            duplicateRecord = true;
            i++;
            numDuplicates++;
        }
        if (duplicateRecord) {
            for (int i = 0; i < numDuplicates; i++) {
                os << "I THINK THIS IS A DUPLICATE RECORD" << endl;
            }
        }
    }
}



// Extra credit functions

double AverageFreshmenGPA(Student data[], const int n) {
    double sumOfGPA = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        
        if (data[i].getCurrClass() == 0) {
            sumOfGPA += data[i].getGPA();
            count++;
            
            // skips the next duplicate records
            while (data[i].getFirstName() == data[i + 1].getFirstName() &&
            data[i].getLastName()         == data[i + 1].getLastName() &&
            data[i].getGPA()              == data[i + 1].getGPA() &&
            data[i].getCurrClass()        == data[i + 1].getCurrClass())
            {
                i++;
            }
        }
        
    }
    
    return (count != 0) ? sumOfGPA / count : 0.0;
}

double AverageSophomoreGPA(Student data[], const int n) {
        double sumOfGPA = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (data[i].getCurrClass() == 1) {
                sumOfGPA += data[i].getGPA();
                count++;
                
                // skips the next duplicate records
                while (data[i].getFirstName() == data[i + 1].getFirstName() &&
                data[i].getLastName()         == data[i + 1].getLastName() &&
                data[i].getGPA()              == data[i + 1].getGPA() &&
                data[i].getCurrClass()        == data[i + 1].getCurrClass())
                {
                    i++;
                }
            }
            
        }
        
        return (count != 0) ? sumOfGPA / count : 0.0;
    }

double AverageJuniorGPA(Student data[], const int n) {
        double sumOfGPA = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (data[i].getCurrClass() == 2) {
                sumOfGPA += data[i].getGPA();
                count++;
                
                // skips the next duplicate records
                while (data[i].getFirstName() == data[i + 1].getFirstName() &&
                data[i].getLastName()         == data[i + 1].getLastName() &&
                data[i].getGPA()              == data[i + 1].getGPA() &&
                data[i].getCurrClass()        == data[i + 1].getCurrClass()) 
                {
                    i++;
                }
            }
            
        }
        
        return (count != 0) ? sumOfGPA / count : 0.0;
    }

double AverageSeniorGPA(Student data[], const int n) {
        double sumOfGPA = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (data[i].getCurrClass() == 3) {
                sumOfGPA += data[i].getGPA();
                count++;
                
                // skips the next duplicate records
                while (data[i].getFirstName() == data[i + 1].getFirstName() &&
                data[i].getLastName()         == data[i + 1].getLastName() &&
                data[i].getGPA()              == data[i + 1].getGPA() &&
                data[i].getCurrClass()        == data[i + 1].getCurrClass())
                {
                    i++;
                }
            }
        }
        
        return (count != 0) ? sumOfGPA / count : 0.0;
    }
