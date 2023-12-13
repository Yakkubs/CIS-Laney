#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <string>
#include <iostream>

template<class T>
struct Node {
	int data;
	Node* next;

};

template<class T>
class MyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	// constructor
	MyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	//copy constructor
	MyLinkedList(MyLinkedList& original){
		if (original.head == nullptr) {
			head = nullptr;
		}
		else {
			while (original.head != nullptr) {
				insert(original.head->data);
				original.head = original.head->next;
			}
		}
	}

	// accessors
	std::string toString() {
		std::string output = "";
		Node<T>* current = head;
		while (current != nullptr) {
			output += std::to_string(current->data) + " - ";
			current = current->next;
		}
		return output;
	}

	// mutators
	void insert(int data) {
		Node<T>* newNode = new Node<T>();
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

	/*void insert(int data, int index) {
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		MyLinkedList<T> tempList;
		int i = 0;
		while (head->next != nullptr) {
			head = head->next;
			i++;
			if (i = index) {
				head->data = data;
				head = head->next;
			}
		}
	}*/
	/*
	void remove(int index) {
		if (head->next == nullptr) {
			return;
		}
		Node<T>* tempNode = head;
		//for (int i = 0; i < index; i++) {
			//tempNode = tempNode->next;
		//}
		int i = 0;
		while (tempNode->next != nullptr) {
			if (i = index) {
				tempNode->next = tempNode->next->next;
			}
			tempNode = tempNode->next;
			i++;
		}

	}*/
	void remove(int index) {
		Node<T>* temp = head;
		if (index == 0) {
			temp = NULL;
		}
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}

	T read(int index) {
		Node<T>* tempNode = head;
		for (int i = 0; i < index; i++) {
			tempNode = tempNode->next;
		}
		T value = tempNode->data;
		return value;
	}

	void change(int value, int index) {
		Node<T>* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->data = value;
	}
	// destructor
	~MyLinkedList() {
		Node<T>* current = head;
		while (current != nullptr) {
			// DEBUGGING
			std::cout << "deleting: " << current->data << std::endl;
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}

};

#endif