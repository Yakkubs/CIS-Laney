#include "MyLinkedList.h"
#include <iostream>   // for debugging only
#include <string>


using namespace std;

MyLinkedList::MyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void MyLinkedList::append(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    // special case: empty list 
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

string MyLinkedList::toString() {
    string output = "";
    Node* current = head;
    while (current != nullptr) {
        output += to_string(current->data) + " - ";
        current = current->next;
    }
    return output;
}

MyLinkedList::~MyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        // DEBUGGING
        cout << "deleting: " << current->data << endl;
        Node* next = current->next;
        delete current;
        current = next;
    }
}