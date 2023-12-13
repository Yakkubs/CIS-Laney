#include <iostream>

using namespace std;

//base converter functions
void binary2Decimal() {
    int binary;

    cout << "Enter the binary number you want to convert to decimal: ";
    cin >> binary;
    int decimal = 0;
    int expoBase = 1;

    while (binary != 0) {
        int lastDigit = binary % 10;
        binary = binary / 10;
        decimal += lastDigit * expoBase;
        expoBase = expoBase * 2;
    }
    cout << "Your converted binary number is equal to: " << decimal;
} 

void decimal2Binary() {
    int decimal;

    cout << "Enter the number you want to convert to binary: "; 
    cin >> decimal;
    string binary = "";
    while (decimal > 0) {
        int remainder = decimal % 2;
        decimal = decimal / 2;
        if (remainder > 0) {
            binary += '1';
        }
        else {
            binary += '0';
        }
    }
    reverse(binary.begin(), binary.end());
    cout << "The binary conversion is: " << binary;
}
 
void binary2Hexadecimal() {
    int binary;
    cout << "Enter the binary number you want to convert to hexadecimal: " << endl;
    cin >> binary;
    int i, temp = 0, hexa[20], rem;
    cout << "the Hexadecimal conversion is: ";
    for (i = 0;binary > 0;i++) {
        for (int y = 0;y < 4;y++) {
            rem = binary % 10;
            binary /= 10;
            temp += rem * pow(2, y);
        }
        hexa[i] = temp;
        temp = 0;
    }
    while (i > 0) {
        i--;
        if (hexa[i] > 9) {
            cout << char(55 + hexa[i]);
        }
        else {
            cout << hexa[i];
        }
    }
}

void hexadecimal2binary() {
    long int i = 0;
    char hexa[100];
    cout << "Enter the hexadecimal code you want to convert: " << endl;
    cin >> hexa;
    cout << "the binary conversion is equal to: ";
    while (hexa[i]){
        switch (hexa[i]){
        case '0': cout << "0000";
            break;
        case '1': cout << "0001";
            break;
        case '2': cout << "0010";
            break;
        case '3': cout << "0011";
            break;
        case '4': cout << "0100";
            break;
        case '5': cout << "0101";
            break;
        case '6': cout << "0110";
            break;
        case '7': cout << "0111";
            break;
        case '8': cout << "1000";
            break;
        case '9': cout << "1001";
            break;
        case 'A': cout << "1010";
            break;
        case 'B': cout << "1011";
            break;
        case 'C': cout << "1100";
            break;
        case 'D': cout << "1101";
            break;
        case 'E': cout << "1110";
            break;
        case 'F': cout << "1111";
            break;
        case 'a': cout << "1010";
            break;
        case 'b': cout << "1011";
            break;
        case 'c': cout << "1100";
            break;
        case 'd': cout << "1101";
            break;
        case 'e': cout << "1110";
            break;
        case 'f': cout << "1111";
            break;
        }
        i++;
    }
}

//Array Manipulation functions
int search(int arr[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == val) {
            return i;
        }
    }
    return -1;
}

void reverse(int arr[], int n) {
    int tempArr[n] = arr;
    int* pointerArray = arr;
    int* pointerArray2 = tempArr;
    for (int i = 0; i < n; i++) {
        *(pointerArray2 + i) = *(pointerArray + ((n - 1) - i));
    }
    arr = tempArr;
}

void oddFirst(int arr[], int n) {

    int* pointerArray = arr;

    int count = 0;

    for (int i = 0; i < n; i++) {

        if ((*(pointerArray + i) % 2) != 0) {

            int temp = *(pointerArray + i);

            *(pointerArray + i) = *(pointerArray + count);

            *(pointerArray + count) = temp;

            count++;

        }

    }

}

int main(){
    //1. base converter main function
    /*int option = 1;
    while (option != 0) {
        cout << "\nWhat conversion would you like to do?: " << endl;
        cout << "1. Binary to Decimal" << endl;
        cout << "2. Decimal to Binary" << endl;
        cout << "3. Binary to Hexadecimal" << endl;
        cout << "4. Hexadecimal to Binary" << endl;
        cout << "Enter 0 to end the program" << endl;
        cin >> option;
        if (option == 1) {
            binary2Decimal();
        }
        if (option == 2) {
            decimal2Binary();
        }
        if (option == 3) {
            binary2Hexadecimal();
        }
        if (option == 4) {
            hexadecimal2binary();
        }
        if (option == 0) {
            break;
        }
    }*/
    //2. Array Manipulation Main function
    int arr[] = { 1, 4, 6, 5, 2, 7, 10 };
    cout << search(arr, 7, 6) << endl;
    reverse(arr, 7);
    oddFirst(arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i];
    }
    return 0;
}