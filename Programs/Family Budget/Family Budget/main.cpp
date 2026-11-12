/*
 Author: Owen Murphy
 Assignment Title: Family Budget
 Assignment Description: Write a program that assists family in keeping track of
    their cash inflows and outflows
 Due Date: 12/02/2019
 Date Created: 11/20/2019
 Date Last Modified: 12/02/2019
 */

/*
 Data Abstraction:
    array of Transaction object to store each transaction
    int numTransactions to store the number of transactions read in
    ifstream inputFile, inputFile2, inputFile3 to open the 3 files
    double balance to store the balance of the account
 Input:
    Open all 3 files to read in the input from each of the files
    call the 2 functions to read in the files
    close all 3 files
 Process:
    for each transaction match the category id with the category id to the file
        and store the description to their respective locations
    call the funtion sortBudget to sort the budget in ascending order by id
 Output:
    call the functions displayHeader and reportInfo to display all the info
    print a warning if the balance was negative
 Assumptions:
    It is assumed that the data read from the files are valid input
 */

#include <iostream>
#include "familyFunctions.h"
#include <fstream>  // ifstream
#include <iomanip>  // setw() setprecision()
#include <string>   // string
#include <cstdlib> // exit()
using namespace std;

const int SIZE = 100;

int main() {
    
    // Data Abstraction
    Transaction transactions[SIZE];
    int numTransactions;
    ifstream inputFile, inputFile2, inputFile3;
    double balance;
    
    inputFile.open("transactions.txt");
    inputFile2.open("categories.txt");
    inputFile3.open("balance.txt");
    if (!inputFile || !inputFile2 || !inputFile3) {
        cout << "Wrong name" << endl;
        exit(1);
    }
    
    // User Input
    numTransactions = readFromTransaction(inputFile, transactions);
    readFromCategories(inputFile2, transactions, numTransactions);
    balance = readBalance(inputFile3);
    inputFile.close();
    inputFile2.close();
    inputFile3.close();
    
    // Data Processing & Output
    displayHeader(cout);
    sortBudget(transactions, numTransactions);
    reportInfo(cout, transactions, numTransactions, balance);

    return 0;
}
