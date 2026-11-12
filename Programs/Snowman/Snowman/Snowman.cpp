/*
Author: Owen Murphy
Assignment Title: Snowman
Assignment Description: Write a program that reads in data from a file
   stores data into the array of snowman objects and reports the data members
   along with the statistical data
Due Date: 12/02/209
Date Created: 11/19/2019
Date Last Modified: 11/25/2019
*/

#include "Snowman.h"

/*
 Description:
    default constructor that instantiates the object data memebers
        to default values
 Return:
    default constructor so no return type
 Precondition:
    data members are invoked to a value whenever the object is instantiated
 Postcondition:
    data members are invoked to a value whenever the object is instantiated
 */
Snowman::Snowman ( ) { //default constructor
    height = 5;
    weight = 300;
    temperature = 29.80;
    hasHat = true;
    scarfColor = "RED";
}

/*
Description:
    constructor that has pass by values setting the private data members
        to their respective values
Return:
    constructor so no return type
Precondition:
    private data members are passed in
    values exist
Postcondition:
    the values of the private data members are changed to the values passed in
*/
Snowman::Snowman(double high, double weh, double temp, bool hat, string col) {
    height = high;
    weight = weh;
    temperature = temp;
    hasHat = hat;
    scarfColor = col;
}

/*
Description:
    mutator function that mutates the value of height to the value passed in
Return:
    void return type, returns nothing
Precondition:
    pass by double value passed in
    value exists
Postcondition:
    the value of height is changed to the value passed in as a parameter
*/
void Snowman::setHeight(double height) {
    this->height = height;
}

/*
Description:
    mutator function that mutates the value of weight to the value passed in
Return:
    void return type, return nothing
Precondition:
    pass by double value
    the value exists
Postcondition:
    the weight data member mutated to the value passed in as a parameter
*/
void Snowman::setWeight(double weight) {
    this->weight = weight;
}

/*
Description:
    mutator function that sets the value of temperature to the value passed in
Return:
    void return type, does not return anything
Precondition:
    value of double passed in as a parameter
    value exists
Postcondition:
    the temperature data member is mutated to the value passed in
*/
void Snowman::setTemperature(double temp) {
    temperature = temp;
}

/*
Description:
    mutator function that sets the value of hasHat to hat
Return:
    void type return, does not return anything
Precondition:
    take in a bool passed in as a parameters
    value exists
Postcondition:
    the value of the objects data member is mutated to the value passed in
*/
void Snowman::setHasHat(bool hat) {
    hasHat = hat;
}

/*
Description:
    mutator function the sets the color data member to the string passed in
Return:
    void type return, does not return anything
Precondition:
    a string value is passed in as a parameters
    the value exists
Postcondition:
    the value of color is mutated to the value passed in
*/
void Snowman::setScarfColor(string col) {
    scarfColor = col;
}

/*
Description:
    accesss function to return the height
Return:
    returns a double value
Precondition:
    objects data members are passed in
Postcondition:
    values are unchanged and the accessor returns the height
*/
double Snowman::getHeight( ) {
    return height;
}

/*
Description:
    the accessor function returns the weight
Return:
    returns a double value
Precondition:
    the objects data members are passed in
Postcondition:
    the values are unchanged and the weight is returned
*/
double Snowman::getWeight( ) {
    return weight;
}

/*
Description:
    accessor function that returns the temperature
Return:
    returns a double value
Precondition:
    the object's data members are passed in
Postcondition:
    the values are unchanged
*/
double Snowman::getTemperature( ) {
    return temperature;
}

/*
Description:
    accessor function that returns the bool value of true or false to has hat
Return:
    returns a boolean value
Precondition:
    the object's data members are passed in
Postcondition:
    the values are unchagned
*/
bool Snowman::getHasHat( ) {
    return hasHat;
}

/*
Description:
    the accessor function returns the string of the color of scarf
Return:
    returns a string
Precondition:
    the object's data members are passed in
Postcondition:
    the values are unchanged
*/
string Snowman::getScarfColor( ) {
    return scarfColor;
}

/*
Description:
    method that calculates the volume of the snowman and returns the result
Return:
    returns a double
Precondition:
    the object's data members are passed in
Postcondition:
    the values of the object's data members are unchanged
*/
double Snowman::Volume( ) {
    return ((PI * pow(height, 3)) / 36.0);
}
//(3.14159 * pow(snowPeople[i].getHeight(), 3)) / 36;

/*
Description:
Return:
Precondition:
Postcondition:
*/
