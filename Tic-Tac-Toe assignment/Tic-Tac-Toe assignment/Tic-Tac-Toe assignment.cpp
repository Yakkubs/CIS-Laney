#include <iostream>
#include <string>

using namespace std;
const int ROW = 3;
const int COLUMN = 3;

void makeBoard(char arr[ROW][COLUMN]){
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COLUMN; j++) {
            arr[i][j] = '*';
        }
    }
}

void printBoard(char arr[ROW][COLUMN]){
    for(int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

bool checkForWin(char arr[ROW][COLUMN]) {
    bool winner = false;

    //checking for win in Row Section:
    for (int i = 0; i < ROW; i++) {
        if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != '*') {
            winner = true;
            break;
        }
    }
    //checking for win in the Column section:
    for (int j = 0; j < COLUMN; j++) {
        if (arr[j][0] == arr[j][1] && arr[j][0] == arr[j][2] && arr[j][0] != '*') {
            winner = true;
            break;
        }
    }
    //checking for diagnole wins:
    if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2]) && arr[1][1] != '*') {
        winner = true;
    }
    return winner;
}

bool checkForTie(char arr[ROW][COLUMN]) {
    int x = 0;
    bool tie = false;
    //creating loops that check every value in the array:
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            //checking for how many values that arent equal to '*' and adding that number into x:
            if (arr[i][j] != '*') {
                x = x + 1;
                //checking to see if x is equal to 9 since that means it checked every value in the array then returning true back the function:
                if (x == 9) {
                    tie = true;
                    break;
                }
            }
        }
    }
    return tie;
}
 
int main() {
    char board[ROW][COLUMN];
    int row, column = 0;
    makeBoard(board);
    printBoard(board);
    for (;;) {
        cout << "Player One, Enter the row and column of where you want to place a X: " << endl;
        cin >> row >> column;
        board[row - 1][column - 1] = 'X';
        printBoard(board);
        checkForWin(board);
        if (checkForWin(board) == true) {
            cout << "player 1 wins!" << endl;
            break;
        }
        checkForTie(board);
        if (checkForTie(board) == true) {
            cout << "No Winner! Players have tied D:" << endl;
            break;
        }
        cout << "Player Two, Enter the row and column of where you want to place an O: " << endl;
        cin >> row >> column;
        board[row - 1][column - 1] = 'O';
        printBoard(board);
        checkForWin(board);
        if (checkForWin(board) == true) {
            cout << "player 2 wins!" << endl;
            break;
        }
        
    }
}