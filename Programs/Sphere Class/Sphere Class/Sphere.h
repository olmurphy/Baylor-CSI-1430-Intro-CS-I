/*
Author: Owen Murphy
Assignment Title: Sphere Class
Assignment Description: Write a program that creates a Sphere object and
    has mutliple useful functions
Due Date: 11/18/2019
Date Created: 11/08/2019
Date Last Modified: 11/18/2019
*/

#ifndef Sphere_h
#define Sphere_h

#include <string>
#include <cmath> // pow()
using namespace std;

const double PI = 3.14159;

class Sphere {
    
private:
    double radius;
    string color;
    
public:

    /*
     Description:
        Default constructor that sets the radius to one and the color to green
     Return:
        no return type of a default costructor
     Precondition:
        has parameters of class' private data members
     Postcondition:
        the private data members, radius and green are set to one and green
            respectively
     */
    Sphere();

    /*
     Description:
        Custom constrcutor constructor that sets the radius to r and the
            color to green
     Return:
        no return type of a costructor
     Precondition:
        takes in a paramter double
        parameter value exists
     Postcondition:
        mutates the radius to paramter passed in
        mutates the color to green
        
     */
    Sphere(double);

    /*
     Description:
        Custom constructor that set the radius to double parameter and
            the color to string paramter passed in.
     Return:
        no return type of a costructor
     Precondition:
        Parameters are pass by values
        the parameter values exist
     Postcondition:
        mutates the private data members radius to the double passed in and
            the color to the string parameter passed in
     */
    Sphere(double, string);

    /*
     Description:
        inline memeber functions mutates the radius to value passed in
     Return:
        void return type, does not return anything
     Precondition:
        double parameter passsed in
        the value exists
     Postcondition:
        the private data member radius is mutated to the double parameter
            passed in
     */
    void setRadius(double);

    /*
     Description:
        constant function that returns the radius
     Return:
        returns a double value
     Precondition:
        takes in class object private data members as parameters
     Postcondition:
        value radius is unchanged and radius is returned
     */
    double getRadius() const;

    /*
     Description:
        inline member function that sets the color of sphere to the string
            parameter passed in
     Return:
        void return type, does no return anything
     Precondition:
        takes in a string parameter alond with the private data members
        the parameter values exist
     Postcondition:
        mutates the color of sphere to the string value passed in
     */
    void setColor(string);

    /*
     Description:
        constant function that returns the color of the sphere
     Return:
        returns a string value
     Precondition:
        private data members of spehere class are returned
     Postcondition:
        the values are unchanged and returns the string private data member
     */
    string getColor() const;

    /*
     Description:
        constant function that calculates the area of sphere using the formula
     Return:
        returns a double value
     Precondition:
        private data members of sphere class are passed in as parameters
     Postcondition:
        private data members are unchanged and returns the area of the sphere
     */
    double area() const;

    /*
     Description:
        constant function that returns the volume of the sphere using the
            formula
     Return:
        returns a type double value
     Precondition:
        private data members of sphere class are passed in as parameters
     Postcondition:
        private data members of sphere class are unchanged and returns the
            volume of the sphere
     */
    double volume() const;

    /*
     Description:
        constant boolean function that returns TRUE if two Sphere have the same
            radius and color, FALSE otherwise
     Return:
        returns a type boolean value
     Precondition:
        takes in the private data member of one sphere class as paramets
            while also using the private data members of the orignial sphere
            class
     Postcondition:
        values of both private data members are unchanged and a boolean value
            is returned
     */
    bool isEqual(const Sphere) const;
};



#endif /* Sphere_h */
