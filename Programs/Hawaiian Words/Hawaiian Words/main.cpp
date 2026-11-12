/*
 Author: Owen Murphy
 Assignment Title: Hawaiian Words
 Assignment Description: Write a program that read valid hawaiian words and
    prints the pronunciation of the word
 Due Date: 10/20/2019
 Date Created: 10/10/2019
 Date Last Modified: 10/20/2019
 */

/*
 Data Abstraction:
    string word to store the string read from standard input and newWord to
        store the phonetically spelled word
    boolean value game to keep asking while after spelling out while the
        condition is false
    boolean value input to have input validation
 Input:
    Read in the word from user input
 Process:
    validate the input word by checking to see if every character is valid
    sound out the word phonetically by using the menu driven guide to help
 Output:
    Print the word to the screen followed by the phonetic spelling of the
        word stored in string variable newWord
 Assumptions:
    It is assumed that the input is valid
    It is assumed that the user knows a character in the alphabet to enter
        so they can leave when asked to play again should they choose to leave
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    
    string word, newWord;
    bool valid = true;
    bool game = true;
    
    while (game) {
        // Ask for the user to enter word and validate to make sure it is in
        // the Hawaiian alphabet
        do {
            cout << "Enter a hawaiian word to pronounce ==> ";
            getline (cin, word);
            cout << word << endl;
            
            valid = true;
            char c;
            
            for (unsigned int i = 0; i < word.size(); ++i) {
                if (valid) {
                    c = word.at(i) = toupper(word.at(i));
                    
                
                    // Check if the word is a hawaiin character
                    
                    switch (c) {
                        case 'P': case 'K': case 'H': case 'L': case 'M':
                        case 'N': case 'W': case 'A': case 'E': case 'I':
                        case 'O': case 'U': case '\'': case ' ':
                            break;
                        default:
                            valid = false;
                            break;
                    }
                }
            }
            
            if(!valid) {
                cout << c << " is not a valid hawaiian character" << endl
                     << endl;
            }
        } while(!valid);
        
        newWord = "";
        
        // loop throught the characters
        for (unsigned int i = 0; i < word.size(); ++i) {
            char c = tolower(word.at(i));
            char nextChar = '1', prevChar = '1';
            
            if (i < word.size() - 1) {
                nextChar = tolower(word.at(i + 1));
            }
            if (i > 0) {
                prevChar = tolower(word.at(i - 1));
            }
            
            
            switch (c) {
                
                case 'p': case 'k': case 'h': case 'l': case 'm': case 'n':
                    newWord += c;
                    break;
                    
                case 'w':
                    if (prevChar == 'i' || prevChar == 'e') {
                        newWord.append("v");
                    }
                    else {
                        newWord.append("w");;
                    }
                    break;
                    
                case 'a':
                    if (nextChar == 'i' || nextChar == 'e') {
                        newWord.append("eye-");
                        ++i;
                    }
                    else if (nextChar == 'o' || nextChar == 'u') {
                        newWord.append("ow-");
                        ++i;
                    }
                    else {
                        newWord.append("ah-");
                    }
                    break;
                    
                case 'e':
                    if (nextChar == 'i') {
                        newWord.append("ay-");
                        ++i;
                    }
                    else if (nextChar == 'u') {
                        newWord.append("eh-");
                        ++i;
                    }
                    else {
                        newWord.append("eh-");
                    }
                    break;
                    
                case 'i':
                    if (nextChar == 'u') {
                        newWord.append("ew-");
                        ++i;
                    }
                    else {
                        newWord.append("ee-");
                    }
                    break;
                    
                case 'o':
                    if (nextChar == 'i') {
                        newWord.append("oy-");
                        ++i;
                    }
                    else if (nextChar == 'u') {
                        newWord.append("ow-");
                        ++i;
                    }
                    else {
                        newWord.append("oh-");
                    }
                    break;
                    
                case 'u':
                    if (nextChar == 'i') {
                        newWord.append("ooey-");
                        ++i;
                    }
                    else {
                        newWord.append("oo-");
                        
                    }
                    break;
                    
                case ' ': case '\'':
                    if (newWord.at(newWord.size() - 1) == '-') {
                        newWord = newWord.substr(0, newWord.size() - 1);
                    }
                    newWord += c;
                    break;
            }
        }
        
        // Take off the last character '-' if it exists
        if (newWord.at(newWord.size() - 1) == '-') {
            newWord = newWord.substr(0, newWord.size() - 1);
        }
        
        // capitalize the first character of the phonetically spelled word
        newWord.at(0) = toupper(newWord.at(0));
        
        // Output the pronunciation of the character
        cout << word << " is pronounced " << newWord << endl << endl;
        
        do {
            cout << "Do you want to enter another word? Y/YES/N/NO ==> ";
            getline(cin, word);
            cout << word << endl;
            
            // lower the response to make comparison easier
            for (unsigned int i = 0; i < word.size(); ++i) {
                word.at(i) = tolower(word.at(i));
            }
            
            valid = true;
            
            if (word == "yes" || word == "y") {
                // don't do anything
            }
            else if (word == "no" || word == "n") {
                game = false;
            }
            else {
                valid = false;
            }
        } while(!valid);
    }
    
    return 0;
}
