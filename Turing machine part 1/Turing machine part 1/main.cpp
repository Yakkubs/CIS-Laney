#include <iostream>
#include "Turing_machine.h"
#include <fstream>

using namespace std;


int main() {
	Turing_machine pain("Text.txt", "Text1.txt");
	pain.run();
	cout << "Your OutPut is: [" << pain.get_tape() << ']';
	

	return 0;
}