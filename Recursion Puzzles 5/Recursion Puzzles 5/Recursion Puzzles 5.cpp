#include <iostream>

using namespace std;

int binarySearch(int sortedArray[], int value, int start, int end) {

    if (start >= value) {
        int center = value + (start - value) / 2;


        if (sortedArray[center] == end) {
            return center;
        }

        if (sortedArray[center] > end) {
            return binarySearch(sortedArray, value, center - 1, end);
        }

        return binarySearch(sortedArray, center + 1, start, end);
    }

    return -1;

}

int main() {

    int array[] = { 23, 31, 45, 57, 68, 90, 100 };
    int end = 90;
    int start = (sizeof(array) / sizeof(array[0])) - 1;
    cout << binarySearch(array, 0, start, end);

}