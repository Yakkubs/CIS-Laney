#include "Turing_machine.h"
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

Turing_machine::Turing_machine(string tape_file, string state_file) {
	ifstream tapeFile;
	tapeFile.open(tape_file);
	read_tape_file(tapeFile);

	ifstream stateFile;
	stateFile.open(state_file);
	read_state_file(stateFile);
}

void Turing_machine::move_left() {
	current_Square -= 1;
}

void Turing_machine::move_right() {
	current_Square += 1;
}

bool Turing_machine::read_square() {
	bool test = false;
	for (int i = 0; i < tape.size(); i++) {
		if (tape[i] == current_Square) {
			test = true;
		}
	}
	return test;
}

void Turing_machine::make_mark() {
	if (read_square() == false) {
		tape.push_back(current_Square);
	}
}

void Turing_machine::remove_mark() {
	if (read_square() == true) {
		int temp;
		for (int i = 0; i < tape.size(); i++) {
			if (tape[i] == current_Square) {
				tape.erase(tape.begin()+i);
			}
		}
	}
}

string Turing_machine::get_tape() {
	stringstream tempTape;
	sort(tape.begin(), tape.end());
	for (int i = 0;i < tape.size(); i++) {
		tempTape << tape[i];
		if(i < tape.size() - 1) {
			tempTape << ", ";
		}
	}
	string tempTape2 = tempTape.str();
	return tempTape2;
}

long Turing_machine::get_current_square() {
	return current_Square;
}

void Turing_machine::read_tape_file(std::ifstream& file) {
	string tempfile;
	string tempCurrentSquare;
	getline(file, tempCurrentSquare, ':');
	current_Square = stoi(tempCurrentSquare);
	while (file.eof()) {
		getline(file, tempfile, ',');
		tape.push_back(stoi(tempfile));
	}
}

void Turing_machine::read_state_file(std::ifstream& file) {
	string tempStateFile;
	int tempState = 0;
	while (!file.eof()) {
		vector<string> tempVec;
		getline(file, tempStateFile, ':');
		tempVec.push_back(tempStateFile);
		getline(file, tempStateFile);
		tempVec.push_back(tempStateFile);
		state.push_back(tempVec);
	}
}

void Turing_machine::update() {
	string temp;
	if (read_square() == false) {
		temp = state[current_State - 1][0];
	}
	else {
		temp = state[current_State - 1][1];
	}
	if (temp.at(0) - 48 == 1) {
		make_mark();
	}
	else {
		remove_mark();

	}
	if (temp.at(1) == 'L') {
		move_left();
	}
	else {
		move_right();
	}
	current_State = temp.at(2) - 48;
	cout << "current state: " << current_State << endl;
}

void Turing_machine::run() {
	while (current_State != 0) {
		update();
	}
}