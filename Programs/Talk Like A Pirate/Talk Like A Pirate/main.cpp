/*
 Author: Owen Murphy
 Assignment Title: Talk Like A Pirate
 Assignment Description: Write a program that reads in english words and their
    pirate translation from a file and outputs the words onto standard output,
    the screen, and into a file name Pirate.txt
 Due Date: 12/09/2019
 Date Created: 12/05/2019
 Date Last Modified: 12/09/2019
 */

/*
 Data Abstraction:
    string fileName to store the name of the data file
    ifstream file to open a file stream to read in data from phrase.txt
        and the file asked from the input screen
    2 parallel arrays of strings to store the english word and their respective
        pirate word
    int numWords to store the number of words read in from file
 Input:
    ask for the name of the file, attempt to open the file, if file is not
        opened print an error message and ask again
    repeat this process until the file is opened successfully
 Process:
    call the function readDataFromFile to read the in data from the file
    store with names in their respective arrays of string
 Output:
    Prints the enlgish words as well as prints the corresponding english words
 Assumptions:
    It is assumed that the file has valid input
 */

#include <iostream>
#include <string> // string getline()
#include <fstream> // ifstream ofstream
#include <ostream> // ostream
#include <sstream> // ostringstream
using namespace std;


// Helper Functions
int readDictionary(ifstream&, string english[], string pirate[]);
string readParagraph(ifstream&);
string translatePirate(string english[], string pirate[], string para, int n);

const int SIZE = 100000;
const int WIDTH = 20;

int main() {

    // Data Abstraction
    string fileName;
    ifstream inputFile, inPhraseFile;
    ofstream outFile;
    string englishWords[SIZE], pirateWords[SIZE];
    int numWords;
    
    // User Input
    do {
        cout << "Enter name of input file: ";
        cin >> fileName;
        cout << fileName << endl;
 
        inputFile.open(fileName);

        if (!inputFile) {
            cout << "Error - File Not Open." << endl;
        }

    } while (!inputFile);

    // Data Processing & Output
    string str1;
    str1 = readParagraph(inputFile);
    inputFile.close();
    
    cout << "\n\n---------------- Original Text ---------------- \n\n";
    cout << str1 << endl;
    
    inPhraseFile.open("PHRASES.txt");
    numWords = readDictionary(inPhraseFile, englishWords, pirateWords);
    inputFile.close();
    
    cout << "\n\n---------------- Pirate Text ---------------- \n\n";
    string pirate = translatePirate(englishWords, pirateWords, str1, numWords);
    cout << pirate << endl;;
    
    outFile.open("Pirate.txt");
    outFile << pirate;
    outFile.close();
 
    return 0;
}

/*
 Description:
    function reads the english words and their translated pirate words into the
        prallel arrays
 Return:
    returns an integer
 Precondition:
    takes in a pass by reference ifstream and 2 arrays of string representing
        the enlgish words and the pirate words
 Postcondition:
    values are filled with the translate words
 */
int readDictionary(ifstream& openFileStream, string englishWord[],
                   string pirateWord[])
{

    string english, pirate;
    
    int numWords = 0;
    while (getline(openFileStream, english, ',')) {
        getline(openFileStream, pirate);
        
        englishWord[numWords] = english;
        pirateWord[numWords] = pirate;
        numWords++;
    }
    
    return numWords;
}

/*
 Description:
    function reads each line from file and stores it into stringstream and
        returns the whole stream in a string
 Return:
    returns a string value
 Precondition:
    takes in a pass by reference ifstream to read data into
    values exist
 Postcondition:
    values are read in from file and the paragraphs are returned
 */
string readParagraph(ifstream& openFileStream) {
    string line, paragraph;
    ostringstream outStream;
    
    while (getline(openFileStream, line)) {
        outStream << line << '\n';
    }
    
    paragraph = outStream.str();
    
    return paragraph;
}


/*
 Description:
    function that transaltes each word into pirate
 Return:
 Precondition:
 Postcondition:
 */
string translatePirate(string englishWords[], string pirateWords[], string para,
                       int n)
{
    string pirate, token, line;
    istringstream stream(para);
    ostringstream outStream;
    bool hasPunct, hasPirate;
    char punctuation;
    

    while (getline(stream, line)) { // read each line
        //cout << "\n Line: " << line << endl;
        istringstream inputString(line);
        string phrase = "";
        
        while (inputString >> token) { // read each phrase
            //cout << "\n Word: " << token << endl;
            hasPunct = false;
            hasPirate = false;
            // take off the punctuation if there is one
            if (!isalpha(token.at(token.size() - 1))) {
                punctuation = token.at(token.size() - 1);
                token = token.substr(0, token.size() - 1);
                hasPunct = true;
            }
            string pirateWord;
            for (int i = 0; i < n; ++i) { // checck the array of english words
                if (englishWords[i] == token) {
                    hasPirate = true;
                    pirateWord = pirateWords[i];
                }
            }
            
            if (hasPirate) {
                outStream << pirateWord;
            }
            else {
                outStream << token;
            }
            
            if (hasPunct) {
                outStream << punctuation << ' ';
            }
            else {
                outStream << ' ';
            }
        }
        outStream << '\n';
        stream.clear();
    }
    pirate = outStream.str();
    
    return pirate;
}

// get rid of punctuation and print pirate word and new line.


