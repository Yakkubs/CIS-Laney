#include <iostream>

using namespace std;

void encrypter(string word) {
    int value = 0;

    for (int i = 0; i < word.length(); i++) {

        if ((int)word[i] >= 97 && (int)word[i] <= 123 || (int)word[i] >= 65 && (int)word[i] < 97) {
            value = (int)word[i] + 13;
            if ((int)word[i] >= 110 && (int)word[i] < 123 || (int)word[i] >= 78 && (int)word[i] < 97) {
                value = (int)word[i] - 13;
            }
        }
        else if ((int)word[i] >= 48 && (int)word[i] <= 57) {
            value = (int)word[i] + 5;
            if ((int)word[i] >= 53) {
                value = (int)word[i] - 5;
            }
        }
        cout << char(value);
    }
}

int main() {

    encrypter("Password0101");

}