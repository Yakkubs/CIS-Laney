#include <iostream>

using namespace std;

string palindrome(string word) {

    if (word.length() == 0 || word.length() == 1) {
        cout << "true";
        return "true";
    }
    else if (word[0] != word[(word.length() - 1)]) {
        cout << "false";
        return "false";
    }

    else if (word[0] == word[(word.length() - 1)]) {
        return palindrome(word.substr(1, word.size() - 2));
    }
}

int main(){
    
    palindrome("tacocat");
    cout << endl;
    palindrome("tacorat");
}
