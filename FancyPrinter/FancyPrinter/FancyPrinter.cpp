#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string name;
string space = " ";
string blank = "";

void userInput() {
	cout << "What is your first name? " << endl;
	cin >> name;
	name = "hello " + name;
}

void hName() {

	cout << "**********************************************************************" << endl;
	int output = (70 - name.length()) / 2;
	for (int count = 3; count < output; count++) {
		blank = blank + space;
		if (name.length() % 2 != 0)
			name = name + " ";
	}
	cout << "***" << blank << name << blank << "***" << endl;
	cout << "**********************************************************************" << endl;
}

int main() {
	userInput();
	hName();
	
}