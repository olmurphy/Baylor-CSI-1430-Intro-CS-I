/*
Author: Owen Murphy
Assignment Title: Family Budget
Assignment Description: Write a program that assists family in keeping track of
   their cash inflows and outflows
Due Date: 12/02/2019
Date Created: 11/20/2019
Date Last Modified: 12/02/2019
*/

#include "familyFunctions.h"


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
Transaction::Transaction () {
    iD = 0;
    w_or_d = 'n';
    amount = 0;
    category = 0;
    categoryDescription = "none";
    
}

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
Transaction::Transaction (int num, char c, double amt, int cat, string des) {
    iD = num;
    w_or_d = c;
    amount = amt;
    category = cat;
    categoryDescription = des;
}

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
Transaction::Transaction (const Transaction& bal) {
    iD = bal.iD;
    w_or_d = bal.w_or_d;
    amount = bal.amount;
    category = bal.category;
    categoryDescription = bal.categoryDescription;
    
}

/*
Description:
    method acts similar to the custom constructor but allows to set an already
        declared object to be the values
Return:
    void return type, does not return anything
Precondition:
    the values of 2 integers, a character, a double, and a string are passed in
        as pass by parameters
    the values exist
Postcondition:
    the values of the data members are changed to the values passed in
*/
void Transaction::setTransaction(int n, char c, double amt, int cat)
{
    iD = n;
    w_or_d = c;
    amount = amt;
    category = cat;
}

/*
Description:
    method sets the description of a transcation to the value passed in as a
        parameter
Return:
    void return type
Precondition:
    takes in string as a pass by parameter
    the value exists
Postcondition:
    the categoryDescription is mutated to the value passed in
*/
void Transaction::setCatDescription(string des) {
    categoryDescription = des;
}

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
int Transaction::get_ID() const {
    return iD;
}

/*
Description:
    method returns the withdrawal or deposit status characer
Return:
    returns a character
Precondition:
    takes in no pass by parameters
Postcondition:
    the values are unchanged and the method returns the w_or_d;
*/
char Transaction::get_w_or_d() const {
    return w_or_d;
}

/*
Description:
    method returns the amount of transaction
Return
    returns a double
Precondition:
    takes in no pass by parameters
Postcondition:
 the values are unchanged and the method returns the amount
*/
double Transaction::getAmount() const {
    return amount;
}

/*
Description:
    method returns the category of transaction
Return:
    returns an integer
Precondition:
    takes in no pass by parameters
Postcondition:
    the values are unchanged and the method returns the category data member
*/
int Transaction::getCategory() const {
    return category;
}

/*
Description:
    method returns the categoryDescription
Return:
    returns a string
Precondition:
    takes in no pass by parameters
Postcondition:
    the values are unchanged and the method returns the categoryDescription
*/
string Transaction::getCatDscription() const {
    return categoryDescription;
}

/*
Description:
    the function takes reads in data from the file and sets each data member
        the the values read in from the files
Return:
    returns an integer
Precondition:
    takes in a pass by reference input file stream, and an array of transcation
        objects
    the values exist
Postcondition:
    the values of each data member are mutated to the values read in from file
*/
int readFromTransaction(ifstream& openFileStream, Transaction data[]) {
    int id, cat, numTransactions = 0;
    char wd;
    double amt;
    string des;
    getline(openFileStream, des); // skips the first line of the data file
    while (openFileStream >> id >> wd >> amt >> cat) {
        data[numTransactions].setTransaction(id, wd, amt, cat);
        numTransactions++;
    }
    return numTransactions;
}

/*
Description:
    the function reads in the description for each category if the category id
        matches the id of transcation then it sets the transcation description
        to the values read in
Return:
    void return type
Precondition:
    takes in an ifstream to read data into, an array of transcation objects and
        an integer to indicate the size of the array
Postcondition:
    the values of each transaction object's description category are mutated
        to the value read in if their is a match with their id's
*/
void readFromCategories(ifstream& openFileStream, Transaction data[], int n) {
    stringstream ss;
    int id;
    string line, des;
    getline(openFileStream, line); // skips first lien of the data file
    while (openFileStream >> id) {
        getline(openFileStream, line);
        des = "";
        for (int i = 0; i < n; ++i) {
            if (data[i].get_ID() == id) {
                ss.clear();
                ss << line;
                
                while (ss >> line) {
                    des += line + " ";
                }
                
                data[i].setCatDescription(des);
            }
        }
    }
}

/*
Description:
    the function read in the balance from a file and returns the balance
Return:
    returns a double value
Precondition:
    takes in a pass by reference input file stream
    the file exists
Postcondition:
    the input data is read into and returns the value read in
*/
double readBalance(ifstream& openFileStream) {
    string line;
    double balance;
    getline(openFileStream, line, '$');
    openFileStream >> balance;
    
    return balance;
}

/*
Description:
    the function puts the data from each transaction of the array into the
        pass by reference output stream
Return:
    void return type
Precondition:
    the pass by refernce output stream, an arrray of transaction objects, an
        integer representing the size of the array, and a double are all passed
        in as parameters
    the valeus exist
Postcondition:
    the values are unchanged and the data is reported
*/
void reportInfo(ostream& os, Transaction data[], int n, double balance) {
    bool negBalance = false;
    int nextID;
    for (int i = 0; i < n; ++i) {
        nextID = data[i].get_ID() + 1;
        balance = updateBalance(data, i, balance);
        os << setw(4) << left << data[i].get_ID()
           << setw(30) << left << data[i].getCatDscription()
           << data[i].get_w_or_d()
           << setw(10) << right << data[i].getAmount()
           << setw(10) << right << balance << endl;
        //os << "compare: " << data[i + 1].get_ID() << " != " << nextID << endl;
        if (data[i + 1].get_ID() != nextID && i != n - 1) {
            os << setw(25) << right << "MISSING TRANSACTION" << endl;
        }
        
        if (balance < 0) {
            negBalance = true;
        }
    }
    
    if (negBalance) {
        os << endl << " ***** WARNING: Negative Balance *****" << endl;
    }
}

/*
Description:
    the function displays the header as shown on the upload site
Return:
    void return type
Precondition:
    takes in a pass by reference output stream
    the values exist
Postcondition:
    the output stream is inserted the header titles
*/
void displayHeader(ostream& os) {
    os << setw(4)  << left << "ID"
       << setw(30) << left << "Category"
       << "T"
       << setw(10) << right << "Amount"
       << setw(10) << right << "Balance"
       << endl << endl;
}

/*
Description:
    the function sorts the budget in order of id
Return:
    void return type
Precondition:
    takes in an array of transaction objects and an integer to indicate the
        size of the array
    the values exist
Postcondition:
    the values are unchanged
*/
void sortBudget(Transaction data[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        
        for (int j = 0; j < n - 1 - pass; j++) {
            if (data[j].get_ID() > data[j + 1].get_ID()) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

/*
Description:
    the function updates the balance depending on the amount of each transacton
Return:
    returns a double value
Precondition:
    takes in an array of transaction objects, an integer indicating the index
        of the array to access and a double
    the values exist
Postcondition:
    the pass by values parameter is updated and is returned 
    
*/
double updateBalance(Transaction data[], int index, double balance) {
    if (data[index].get_w_or_d() == 'W') {
        balance -= data[index].getAmount();
    }
    else {
        balance += data[index].getAmount();
    }
    return balance;
}

