#include "Assignment4.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

CommonAlg2::CommonAlg2() {
	array = new int[size];
	tempArray = nullptr;
	ifstream iFile;
	//iFile.open("1to1000.txt");
	iFile.open("1000RandomNumbers.txt");
	int i = 0;
	while (!iFile.eof()) {
		iFile >> array[i];
		i++;
	}
	iFile.close();
}

void CommonAlg2::method1() {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ", ";
	}
}
int CommonAlg2::method2() {
	int temp = 0;
	for (int i = 0; i < size; i++) {
		temp += array[i];
	}
	return temp;
}
void CommonAlg2::method3() {
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 != 0) {
			cout << array[i] << " ";
		}
	}
}
void CommonAlg2::method4() {
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 == 0) {
			cout << array[i] << " ";
		}
	}
}
void CommonAlg2::method5(int guess) {
	method11NoPrint();
	int count = 0;
	int low = 0;
	int high = size-1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (guess == tempArray[mid]) {
			cout << "found at index: " << mid;
			break;
		}
		if (tempArray[mid] < guess) {
			low = mid + 1;
		}
		else {
			high = mid -1;
		}
		count++;
	}
	cout << " this took: " << count << " iterations";
}
void CommonAlg2::method6() {
	cout << array[size / 2];
}
void CommonAlg2::method7() {
	cout << array[0];
}
void CommonAlg2::method8() {
	cout << array[size-1];
}
void CommonAlg2::method9(){
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] > array[index]) {
			index = i;
		}
	}
	cout << "Largest value in the Array is: " << array[index] << " at index: " << index << endl;
}
void CommonAlg2::method10() {
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] < array[index]) {
			index = i;
		}
	}
	cout << "Smallest value in the Array is: " << array[index] << " at index: " << index << endl;
}
void CommonAlg2::method11NoPrint() {
	int temp;
	tempArray = new int[size];
	for (int i = 0; i < size; i++) {
		tempArray[i] = array[i];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (tempArray[j] > tempArray[j + 1]) {
				temp = tempArray[j + 1];
				tempArray[j + 1] = tempArray[j];
				tempArray[j] = temp;
			}
		}
	}
}
void CommonAlg2::method11() {
	method11NoPrint();
	for (int i = 1; i < size; i++) {
		cout << tempArray[i] << ", ";
	}
}
void CommonAlg2::method12() {
	int value = method2()/size;
	cout << "Mean value: " << value;
}
void CommonAlg2::method13() {
	method11NoPrint();
	cout << tempArray[(size -1) / 2];
}
void  CommonAlg2::method14() {
	int temp;
	int temp2 = 0;
	int value = array[0];
	for (int i = 0; i < size; i++) {
		temp = 1;
		for (int j = i+1; j < size; j++) {
			if (array[j] == array[i]) {
				temp++;
			}
		}
		if (temp > temp2) {
			value = array[i];
			temp2 = temp;
		}
	}
	cout << "median: " << value;
}
CommonAlg2::~CommonAlg2() {
	delete[] array;
	delete[] tempArray;
}