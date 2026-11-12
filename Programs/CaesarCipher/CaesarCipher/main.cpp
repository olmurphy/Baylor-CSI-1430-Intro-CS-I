/*
 Author: Owen Murphy
 Assignment Title: CeaserCipher
 Assignment Description: Write a program that either encodes or decodes a crypt
    depending on what the user asks
 Due Date: 10/04/2019
 Date Created: 10/03/2019
 Date Last Modified: 10/04/2019
 */

/*
 Data Abstraction:
    File name to read a file, encode/decode string to determine whether to
        encode or decode a message
    inputFile delcared as input file stream to open the file
    output file stream declared to open the message file
 Input:
    ask the for file name and ask the user for encrypt or decrypt
 Process:
    Open the file, encode the file message or decode the file message and
        message onto a file named message
 Output:
    Print out each character encoded or decoded to the screen
 Assumptions:
    It is assumed that the file exists and is entered correctly
 */


#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    
    // Data Abstraction
    string fileName;
    string encOrDec;
    ifstream inputFile;
    ofstream file;
    int countA = 0, countE = 0, countI = 0;
    int countO = 0, countU = 0, countY = 0;
    int shift = 3;
    char c;
    
    
    // Input
    cout << "Enter File Name: ";
    cin >> fileName;
    cout << fileName << endl;
    cout << "Enter encrypt or decrypt: ";
    cin >> encOrDec;
    cout << encOrDec << endl;
    
    
    // Process
    
    if ((encOrDec != "encrypt") && (encOrDec != "decrypt")) {
        cout << "Error: Bad Command." << endl;
        exit(1);
    }
    else {
        inputFile.open(fileName);
        if (inputFile.fail()) {
        cout << "Error: File did NOT open." << endl;
        exit(1);
        }
    }
    
    file.open("message");
    
    while (inputFile.get(c)) {
        if(c == 'a' || c == 'A') {
            countA++;
        }
        if(c == 'e' || c == 'E') {
            countE++;
        }
        if(c == 'i' || c == 'I') {
            countI++;
        }
        if(c == 'o' || c == 'O') {
            countO++;
        }
        if(c == 'u' || c == 'U') {
            countU++;
        }
        if(c == 'y' || c == 'Y') {
            countY++;
        }
            
        if (encOrDec == "encrypt") {
            c += shift;
            cout << c;
            file << c;
        }
        else {
            c -= shift;
            cout << c;
            file << c;
        }
    }
    inputFile.close();
    file.close();
    cout << endl << endl << "*** Start Extra Credit ***" << endl << endl;
    
    // Extra Credit Output
    cout << "Letter Frequency" << endl;
    cout << "   A     " << countA << endl;
    cout << "   E     " << countE << endl;
    cout << "   I     " << countI << endl;
    cout << "   O     " << countO << endl;
    cout << "   U     " << countU << endl;
    cout << "   Y     " << countY << endl;
    
    cout << endl << "*** End Extra Credit ***" << endl;
    
    
    // Output

       
    
    return 0;
}
