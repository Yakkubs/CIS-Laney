#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 5;


void getInput(int ar[], int inputIndex) {
    cout << "please enter a number: " << endl;
    cin >> ar[inputIndex];
}

void printArray(int ar[]) {
    int printIndex = 0;
    while (printIndex < ARRAY_SIZE) {
        cout << ar[printIndex] << endl;
        printIndex++;
    }
}

int main() {
    int theArray[ARRAY_SIZE];
    int inputIndex = 0;
    while (inputIndex < ARRAY_SIZE) {
        getInput(theArray, inputIndex);
        inputIndex++;
    }
    printArray(theArray);

    return 0;
}