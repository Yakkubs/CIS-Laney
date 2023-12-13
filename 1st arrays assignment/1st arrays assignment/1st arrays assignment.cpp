#include <iostream>
#include <string>
using namespace std;

void printAverage(int userArray[], int arraySize) {

	int count;
	float average;
	float total = 0;

	for (count = 0; count < arraySize; count++) {
		
		total += userArray[count];

	}
	average = total / arraySize;
	cout << average << endl;
}

float returnAverage(int userArray[], int arraySize) {

	int count;
	float average;
	float total = 0;

	for (count = 0; count < arraySize; count++) {

		total += userArray[count];

	}
	average = total / arraySize;
	return average;
}

string retrunLongest(string userArray[], int arraySize) {
	int i = 0;

	for (int count = 0; count < arraySize; count++) {

		if (userArray[count].length() > userArray[i].length()) {
			i = count;
		}
		
	}
	return userArray[i];
}

int main() {
	printAverage();

}