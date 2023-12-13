#include <iostream>

using namespace std;

unsigned int reverse(unsigned int number) {

	if (number < 10) {
		cout << number;
		return 0;
	}
	int remainder = number % (10);
	cout << remainder;
	reverse(number / 10);

}

int main() {
	int number = 987654321;
	reverse(number);

}
