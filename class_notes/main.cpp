/*
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int minIndex, maxIndex;
    int min, max;
    int size = rand();
    int array[size];

    for(int i = 0; i < size; i++){
        array[i] = rand();
    }

    minIndex = maxIndex = 0;

    for(int i = 0; i < size; i++){
        if(array[minIndex] > array[i]){
            minIndex = i;
        }
        else if(array[maxIndex < array[i]){
            maxIndex = i;
        }
    }

    cout << "Min = " << array[minIndex] << endl;
    cout << "Max = " << array[minIndex] << endl;
    cout << "MaxIndex = " << minIndex << endl;
    cout << "MinIndex = " << minIndex << endl;

    int value;
    do{
        cout << "Enter ID number: ";
        cin id_number;

        if(id_number <= 10 && id_number <= 1){
        index = 0;
        while(id[index] != id_number){
            index++;
        }
        cout << name[index] << " " << gpa[index] << " "
        << age[index] << endl;
        }
    }while(value != -1)

    return 0;
}
