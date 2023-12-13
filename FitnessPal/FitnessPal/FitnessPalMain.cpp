#include <iostream>
#include "FitnessPal.h"
using namespace std;

int main() {
	cout << "WELCOME TO FitnessPal :D" << endl;
	FitnessPal yak;
	cout << "What do you want to do?" << endl;
	cout << "1: Find Maintence Cals" << endl;
	cout << "2: Find Bench Press ORM Average" << endl;
	cout << "3: Find Squat ORM Average" << endl;
	cout << "4: Find Dead Lift ORM Average" << endl;
	cout << "5: Add daily calorie total" << endl;
	cout << "6: Water Intake" << endl;
	cout << "7: save and quit" << endl;
	//cout << "Enter choice: " << endl;
	int choice;
	bool loopCon = true;
	while (loopCon == true) {
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				yak.maintenanceCalFinder();
				cout << ", If your goal is to lose/gain weight, eat 500 calories less/more a day then this number to lose/gain 1 pound a week(recommended target weekly weight change)" << endl;
				break;
			case 2: 
				yak.findBenchPrAvgBasedOnWeight('A');
				cout << endl;
				break;
			case 3:
				yak.findSquatPrAvgBasedOnWeight('A');
				cout << endl;
				break;
			case 4:
				yak.findDeadliftPrAvgBasedOnWeight('A');
				cout << endl;
				break;
			case 5:
				yak.calorieIntake();
				cout << endl;
				break;
			case 6:
				yak.waterIntake();
				cout << endl;
				break;
			case 7:
				yak.save();
				loopCon = false;
				break;
			default:
				cout << "Invalid choice!" << endl;
		}
		yak.save();
	}
}