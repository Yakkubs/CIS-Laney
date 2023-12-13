#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Étude 1:
void printTwice(string x) {
    for (int i = 0; i < 2; i++) {
        cout << x << endl;
    }
}


int main(){
    printTwice("cheese");
}

//Étude 2:
void printMany(string word, int number) {
    for (int i = 0; i < number; i++) {
        cout << word << endl;
    }
}

int main() {
    string word;
    int number;
    cout << "Please enter a string then a number" << endl;
    cin >> word >> number;
    printMany(word, number);
}

//Étude 3:
void multiHello(int x) {
    for (int i = 0; i < x; i++) {
        cout << "hello" << endl;
    }
}

int main() {
    multiHello(5);
}

//Étude 5:
string returnString(string word) {
    word.at(0) = 'j';
    return word;
}

int main(){
    string x = "hello";
    cout << returnString(x);
}

//Étude 6:
void changeByReference(string &x) {
    x.at(0) = 'j';
    cout << x << endl;
}

int main() {
    string x = "hello";
    changeByReference(x);
    cout << x;
}

//Étude 7:

int main() {
    int x = 137;
    int t = 42;
    int *y = &x;
    int *g = &t;
   
    changePointer(g);
    cout << g << endl;
    cout << x;
}

//Étude 8:

void changePointer(int *y) {
    *y = 137;
}

int main() {
    int x = 137;
    int t = 42;
    int *y = &x;
    int *g = &t;

    //I assumed that it was going to print the value, but it ended up printing the adress of the variable, unless i coded this wrong
    changePointer(g);
    cout << g << endl;
    cout << x;
}