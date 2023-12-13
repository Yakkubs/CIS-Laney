#include <iostream>
//#include <string>

using namespace std;

const int ROW = 12;
const int COLUMN = 12;
const char WHITE_SQUARES = '+';
const char BLACK_SQUARES = '-';


void makeBoard(char arr[ROW][COLUMN]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {

            if ((i+j) % 2 == 0) {
                arr[i][j] = WHITE_SQUARES;
            }
            if ((i + j) % 2 != 0) {
                arr[i][j] = BLACK_SQUARES;
            }
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main(){
    char array[ROW][COLUMN];
    makeBoard(array);
}

