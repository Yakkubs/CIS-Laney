#include <iostream>

using namespace std;

int arrayMultiplier(int array[], int size) {
	if (size == 0) {
		return array[0];
	}
	return array[size] * arrayMultiplier(array, size - 1);
}

int main() {

	int array[] = { 1,2,3,4,5, };
	int size = (sizeof(array) / sizeof(array[0]) - 1);

	cout << arrayMultiplier(array, size);

}