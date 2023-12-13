#include <iostream>
using namespace std;

void decToBinary(int number){
    string result;
    while (number > 0) {
        int remainder = number % 2;
        number = number / 2;
        if (remainder > 0) {
            result = result + '1';
        }
        else {
            result = result + '0';
        }
    }
    reverse(result.begin(), result.end());
    cout << "The binary code is: " + result;
}

int main(){
    int number;
    cout << "Enter the number you want to convert to binary code: ";
    cin >> number;
    decToBinary(number);
    return 0;
}