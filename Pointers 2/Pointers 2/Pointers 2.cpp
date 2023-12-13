#include <iostream>

using namespace std;

int* resizeArray(int array[], int& size) {

    int* newArray = new int[size * 2];

    for (int i = 0; i < size * 2; i++) {
        if (i < size) {
            newArray[i] = array[i];
        }
        else {
            newArray[i] = 0;
        }
    }
    delete [] array;

    return newArray;
}

int main() {
    int size = 5;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = {i+1};
    }
    int* pointer = resizeArray(array, size);

    for (int i = 0; i < size * 2; i++) {
        cout << pointer[i];
    }
}