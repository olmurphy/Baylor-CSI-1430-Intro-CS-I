

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void bubbleSort(int [], int);

int main() {
    
    int size = 100000;
    int a[size];
    for (int i = 0; i < size; i++) {
        a[i] = rand() % size;
    }
    
    int start = clock();
    
    bubbleSort(a, size);
    
    int stop = clock();
    
    cout << "Time = " << stop - start << endl;
    
    
    
    return 0;
}


void bubbleSort(int a[], int n) {
    
    for (int pass = 0; pass < n - 1; pass++) {
        
        for (int j = 0; j < n - 1; j++) {
            
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}
