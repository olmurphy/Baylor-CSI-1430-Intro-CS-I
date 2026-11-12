/*
Author: Owen Murphy
Assignment Title: Sphere Class
Assignment Description: Write a program that creates a Sphere object and
    has mutliple useful functions
Due Date: 11/18/2019
Date Created: 11/08/2019
Date Last Modified: 11/18/2019
*/

/*
 Data Abstraction:
    string fileName to store the name of the file
    ifstream file to open a file stream for reading input
    constant integer of sphere size equal to 100
    array of Sphere of size SPHERE_SIZE
 Input:
    Ask the user for the file name and continue asking until the file opens
    Read in the file the first two lines to skip
    After start reading in the radius and the color of the sphere and keep
        reading in the input until no more data
 Process:
    set the radius and color to the radius and color read in from data file
        to their respective locations
 Output:
    print the radius number, the radius, the color, the area, and the volume
        of each sphere in the format as indicated on the upload site
 Assumptions:
    It is assumed that the data is valid input data
    It is assumed that there are no more than 100 spheresss
 */

#include <iostream>
#include "Sphere.h"
#include <string>       // string
#include <fstream>      // ifstream
#include <iomanip>      // fixed, setprecision()
#include <ios>
using namespace std;

const int SPHERE_SIZE = 100;
const int WIDTH = 12;
int main() {
    
    // Data Abstraction
    string fileName;
    ifstream file;
    Sphere Spheres[SPHERE_SIZE];
    int numRedSpheres;
    int volumesOver;
    double sumArea;
    int numSpheres;
    
    // User Input
    do {
        cout << "Enter file name: ";
        cin >> fileName;
        cout << fileName << endl;
        file.open(fileName.c_str());
        if(!file) {
            cout << "Error: File Not Open." << endl;
        }
    } while(!file);
    
    // Data Processing and Output
    getline(file, fileName); // skip first two lines of file
    getline(file, fileName); // skip first two lines of file
    
    double radius;
    string color;
    numSpheres = 0;
    
    while (file >> radius >> color) {
        Spheres[numSpheres].setRadius(radius);
        Spheres[numSpheres].setColor(color);
        
        numSpheres++;
    }
    
    cout << setw(WIDTH) << "Number" << setw(WIDTH) << "Radius"
         << setw(WIDTH) << "Color"  << setw(WIDTH) << "Area"
         << setw(WIDTH) << "Volume" << endl;
    
    numRedSpheres = 0;
    volumesOver = 0;
    sumArea = 0;
    
    cout << fixed << setprecision(2);
    for (int j = 0; j < numSpheres; ++j) {
        double area;
        double volume;
        
        
        area = Spheres[j].area();
        volume = Spheres[j].volume();
        
        sumArea += area;
        
        if(Spheres[j].getColor() == "red") {
            numRedSpheres++;
        }
        if(volume > 215) {
            volumesOver++;
        }
        cout << setw(WIDTH) << j
             << setw(WIDTH) << Spheres[j].getRadius()
             << setw(WIDTH) << Spheres[j].getColor()
             << setw(WIDTH) << area
             << setw(WIDTH) << volume;
        cout << endl;
    }
   
    cout << endl << "Total Number of Spheres = " << numSpheres << '.' << endl;
    cout << (static_cast<double>(numRedSpheres) / numSpheres) * 100
         << "% of Spheres are red." << endl;
    cout << volumesOver << " Spheres have a Volume over 215." << endl;
    cout << "Average Area = " << sumArea / numSpheres << endl;
   
    file.close();
    return 0;
    
}
