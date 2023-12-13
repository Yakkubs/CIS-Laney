#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

	int userInput;

	cout << "Enter Any Real Number:" << endl;
	cin >> userInput;
	string n = "*";
	string nO = "";

	for (int counter = -1; counter < userInput; counter++) {
		int output = pow(2, counter + 1);
		for (int counter = 0; counter < output; counter++) {
			nO = nO + n;
		}
		cout << nO << endl;
		nO = "";
	}
	for (int counter = userInput; counter > -1; counter--) {
		int output2 = pow(2, counter-1);
		for (int counter = 0; counter < output2; counter++) {

			nO = nO + n;
		}
		cout << nO << endl;
		nO = "";
	}
}