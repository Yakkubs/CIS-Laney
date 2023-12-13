#include <iostream>
#include <string>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 8;

void turnLeft(string &direction) {
	if (direction == "east") {
		direction = "north";
	}
	else if (direction == "north") {
		direction = "west";
	}
	else if (direction == "west") {
		direction = "south";
	}
	else if (direction == "south") {
		direction = "east";
	}
}

void move(int &row, int &column, string direction) {
	if (direction == "east") {
		column++;
	}
	if (direction == "north") {
		row--;
	}
	if (direction == "west") {
		column--;
	}
	if (direction == "south") {
		row++;
	}

}

int main() {
	string x;
	string direction = "east";
	int row = 0;
	int column = 0;
	while (x != "quit") {
		cout << "Please enter a command:" << endl;
		cin >> x;
		if (x == "turnLeft();") {
			turnLeft(direction);
		}
		else if (x == "move();") {
			move(row, column, direction);
			if (row > ROWS || row < 0 || column > COLUMNS || column < 0) {
				cout << "Karel is at location " << "(" << row << "," << column << ") " << "facing " << direction << "." << " Karel has crashed!" << endl;
				break;
			}
		}
		else if (x == "quit") {
			cout << "Karel is at location " << "(" << row << "," << column << ") " << "facing " << direction << "." << " Thank you for not crashing Karel!" << endl;
			break;
		}
		else
			cout << "invalid command!" << endl;

		cout << "Karel is at location " << "(" << row <<"," << column << ") " << "facing " << direction << "." << endl;
	}
}