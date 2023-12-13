#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float amountDue;
float amountReceived;
int Dollars;
int Quarters;
int Dimes;
int Nickels;
int Pennies;

int main() {

	cout << "Enter The Amount Due: " << endl;
	cin >> amountDue;
	cout << "Enter the Amount Received: " << endl;
	cin >> amountReceived;

	int amountDue1 = amountDue * 100;
	int amountReceived1 = amountReceived * 100;
	int change = amountReceived1 - amountDue1;

	if (change > 0) {

		Dollars = change / 100;
		change = change % 100;
		Quarters = change / 25;
		change = change % 25;
		Dimes = change / 10;
		change = change % 10;
		Nickels = change / 5;
		change = change % 5;
		Pennies = change / 1;
		cout << Dollars << " Dollars, " << Quarters << " Quarters, " << Dimes << " Dimes, " << Nickels << " Nickels, and " << Pennies << " Pennies" << endl;
	}
	
	if (change < 0) {

		cout << "Insufficient funds!" << endl;
	}
	
	return 0;
}