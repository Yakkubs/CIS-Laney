#include <iostream>
#include "MyLinkedList.h"

using namespace std;

int main() {
    MyLinkedList<int> firstList;

    cout << "before adding elements: " << endl;
    cout << firstList.toString() << endl;

    cout << "after adding one element" << endl;
    firstList.insert(42);
    cout << firstList.toString() << endl;

    cout << "after adding a bunch of elements" << endl;

    for (int i = 0; i < 5; i++) {
        firstList.insert(i * 2);
    }
    cout << firstList.toString() << endl;
    MyLinkedList<int> secondList(firstList);
    secondList.remove(1);
    cout << "second list" << endl << secondList.toString() << endl;

}