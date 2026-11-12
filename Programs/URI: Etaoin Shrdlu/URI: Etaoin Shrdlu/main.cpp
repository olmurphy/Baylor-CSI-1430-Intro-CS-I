/*
 Author: Owen Murphy
 Assignment Title: URI: Etaoin Shrdlu
 ASsignment Description: Write a program that reads input and determines the
    top 5 digrams read in from input. Prints the top with their frequencies and
    their relative frequencies
 Due Date: 12/04/2019
 Date Created: 11/22/2019
 Date Last Modified: 12/04/2019
 */

/*
 Data Abstraction:
    array of strings digrams to store the digrams of the lines
    array of integers count to store their respective frequencies
    integer numLine to store the number of lines to read in
    integer numDigrams to store the number of digrams read from input
    string line to store each line in input
    string sentence to store the whole sentence
 Input:
    read in an integer indicated the number of lines to read input from,
        while reading input, add each line onto the line to get the full
        sentece
    integer total digrams to store the total number of digrams from the input
 Process:
    start processing the sentece by taking sets of 2 characters into a string
        starting at position 0 and call the function find the adds the string
        of 2 characters to the array digrams if the string is not already in
        the array. If the string is in the array, return the index that it is
        in and increment the respective index of array of integers named count
    sort the parallel arrays by their frequencies then by lexicographical
        order
 Output:
    print the top 5 freuquences and the corresponding digram along with their
        relative frequencies
 Assumptions:
    It is assumed that all input data is valid data
 */

#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>
using namespace std;

const int SIZE = 2000;

int find(string digrams[], string, int&);
void display(ostream&, string di[], int num[], int);
void sortCount(string digrams[], int count[], int);
void sortDigram(string digrams[], int count[], int);

int main() {

    // Data Abstraction
    string digrams[SIZE];
    int count[SIZE];
    int numLine;
    int numDigrams;
    string line;
    string sentence;
    int totalDigrams;
    
    // User Input
    cin >> numLine;

    while (numLine > 0) {
        
        // Set each parallel arrays to default values
        for (int i = 0; i < SIZE; i++) {
            count[i] = 0;
            digrams[i] = "";
        }
        
        sentence = "";
        
        cin.ignore(); // skips the new line character
        for (int i = 0; i < numLine; ++i) {
            getline(cin, line);
            sentence += line;
        }
        
        // Data Processing & Output
        numDigrams = 0;
        for (unsigned int i = 0; i < sentence.size() - 2; i++) {

            line = sentence.substr(i, 2);
            count[find(digrams, line, numDigrams)]++;
        }
        
        sortDigram(digrams, count, numDigrams);
        sortCount(digrams, count, numDigrams);

        totalDigrams = sentence.size() - 1;
        display(cout, digrams, count, totalDigrams);
        cout << endl;
        
        cin >> numLine;
    }
    
    return 0;
}





/*
 Description
    function that searches for the string token, if it finds the token, then
        the index where it is found is returned. If it is not found then the
        token is added to the end and the index where it was added is returned
        and the pass by reference integer n representing the number of digrams
        is incremented
 Return
    void return type
 Precondition
    takes in an array of digram strings
    the avlues exist
 Postcondition
    the token is added to the end of the array of digrams if the token is not
        found in the digram
 
 */
int find(string digrams[], string token, int& n) {
    int index;
    bool found = false;
    
    for (int i = 0; i < n + 1 && !found; ++i) {
        if (digrams[i] == token) {
            found = true;
            index = i;
        }
    }
    
    if (!found) {
        digrams[n] = token;
        index = n;
        n++;
    }

    return index;
}

/*
 Description
    function sorts the count in ascending order. Swaps both the count and
        digram arrays
 Return
    void return type
 Precondition
    takes in an array of digrams, an array of count, and an integer numDi
        representing the number of digrams read in
 Postcondition
    the values are unchanged but they are sorted in ascending order
 */
void sortCount(string digrams[], int count[], int numDi) {
    for (int pass = 0; pass < numDi - 1; pass++) {
        
        for (int j = 0; j < numDi - 1 - pass; j++) {
            if (count[j] < count[j + 1]) {
                swap(count[j], count[j + 1]);
                swap(digrams[j], digrams[j + 1]);
            }
        }
    }
}

/*
 Description:
    function that sorts the digram by lexicographical order
 Return:
    void return type
 Precondition:
    takes in an array of strings, array of integers, and an integer
        representing the size of the parallel arrays
    the values exist
 Postcondition:
    the values are unchanged and the order in which they are in the array is
        sorted if they are out of order
 */
void sortDigram(string digrams[], int count[], int numDi) {
    for (int pass = 0; pass < numDi - 1; pass++) {
        
        for (int j = 0; j < numDi - 1 - pass; j++) {
            
            if (digrams[j] > digrams[j + 1]) {
                swap(digrams[j], digrams[j + 1]);
                swap(count[j], count[j + 1]);
            }
        }
    }
}

/*
 Description:
    function prints the top five most frequent digrams and their frequencies
        along with their relative frequences
 Return:
    void return type
 Precondition:
    takes in a pass by reference ostream, array of strings, an array of
        integers, and an integer
    the values exist
 Postcondition:
    the values are unchanged and the report is reported
 */
void display(ostream& os, string di[], int num[], int numDigrams) {
    
    for (int i = 0; i < 5; ++i) {
        os << setw(3) << left << di[i] << " " << num[i]
           << " " << fixed << setprecision(6)
           << static_cast<double>(num[i]) / numDigrams << endl;
    }
}
