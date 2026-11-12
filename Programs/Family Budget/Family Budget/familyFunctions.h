/*
Author: Owen Murphy
Assignment Title: Family Budget
Assignment Description: Write a program that assists family in keeping track of
   their cash inflows and outflows
Due Date: 12/02/2019
Date Created: 11/20/2019
Date Last Modified: 12/02/2019
*/

#ifndef familyFunctions_h
#define familyFunctions_h

#include <string> // string
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <iostream>
#include <ostream> // ostream
#include <iomanip> // setw() setprecision()
using namespace std;


class Transaction {
private:
    int iD;
    char w_or_d;
    double amount;
    int category;
    string categoryDescription;
public:
    
    /*
    Description:
       Default constructor initializes data members to default values
    Return:
       default constructor does not have a return type
    Precondition:
       object's data members are passed in as parameters
    Postcondition:
       object members are set the their defualt values
    */
    Transaction ();
    
    /*
    Description:
       Customer constructor mutates the data members to the values passed in as
           parameters
    Return:
       does not have return type
    Precondition:
       takes two integers, character, doube, and a string as parameters
       the values exist
    Postcondition:
       the values are mutates to the pass by parameters
    */
    Transaction (int, char, double, int, string);
    
    /*
    Description:
        copy constructor copies the values of the object and mutates the values
            the to pass by values
    Return:
        does not have a return type
    Precondition:
        takes in a object of transaction
        The values exists
    Postcondition:
        the values of the object are mutated to the values passed in
    */
    Transaction (const Transaction&);
    
    /*
    Description:
        method acts similar to the custom constructor but allows to set an
            already declared object to be the values
    Return:
        void return type, does not return anything
    Precondition
        the values of 2 integers, a character, a double, and a string are
            passed in as pass by parameters
        the values exist
    Postcondition:
        the values of the data members are changed to the values passed in
    */
    void setTransaction(int, char, double, int);
    
    /*
    Description:
        method sets the description of a transcation to the value passed in as
            a parameter
    Return:
        void return type
    Precondition:
        takes in string as a pass by parameter
        the value exists
    Postcondition:
        the categoryDescription is mutated to the value passed in
    */
    void setCatDescription(string);
    
    /*
    Description:
        the method returns the id of the object
    Return:
        returns an integer
    Precondition:
        take in no pass by parameters
    Postcondition:
        the values are unchanged and returns the id data member
    */
    int get_ID() const;
    char get_w_or_d() const;
    double getAmount() const;
    int getCategory() const;
    string getCatDscription() const;
};

int readFromTransaction(ifstream& openFileStream, Transaction data[]);
void readFromCategories(ifstream& openFileStream, Transaction data[], int n);
double readBalance(ifstream& openFileStream);
void reportInfo(ostream&, Transaction data[], int n, double balance);
void displayHeader(ostream&);
void sortBudget(Transaction data[], int n);
double updateBalance(Transaction data[], int n, double balance);

#endif /* familyFunctions_h */
