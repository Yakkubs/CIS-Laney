#include <iostream>

using namespace std;

void countDown(unsigned int number) {

	if (number == 0) {

		cout << "BLAST OFF!";

	}

	else{

		cout << number << " ";

		countDown(number - 1);
	}

}

int main() {
	countDown(10);

}