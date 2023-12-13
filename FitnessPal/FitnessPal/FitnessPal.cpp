#include "FitnessPal.h"
#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <time.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

FitnessPal::FitnessPal(){
	userData.open("UserData.txt");
	if (userData.peek() == EOF) {
		userData.clear();
		cout << "Enter your height(cm): ";
		cin >> height;
		userData << "Height = " << height << endl;
		cout << "Enter your weight: ";
		cin >> weight;
		userData << "Weight = " << weight << endl;
		cout << "Enter your age: ";
		cin >> age;
		userData << "Age = " << age << endl;
		cout << "Are you male or female? Enter (M) for male or (F) for female: ";
		cin >> sex;
		userData << "Sex = " << sex << endl;
		activityAccessor();
		cout << "Enter Bench Press PR( if you dont know, enter 0): ";
		cin >> benchPR;
		if (benchPR == 0) {
			findBenchPrAvgBasedOnWeight('B');
			cout << "Calculated bench PR is: " << benchPR << endl;
		}
		userData << "Bench Press Pr = " << benchPR << endl;
		cout << "Enter back squat PR( if you dont know, enter 0): ";
		cin >> squatPR;
		if (squatPR == 0) {
			findSquatPrAvgBasedOnWeight('B');
			cout << "Calculated back squat PR is: " << squatPR << endl;
		}
		userData << "Squat Pr = " << squatPR << endl;
		cout << "Enter back DealLift PR( if you dont know, enter 0): ";
		cin >> deadLiftPR;
		if (deadLiftPR == 0) {
			findDeadliftPrAvgBasedOnWeight('B');
			cout << "Calculated back deadlift PR is: " << deadLiftPR << endl;
		}
		userData << "Deadlift Pr = " << deadLiftPR << '\n' << " " << endl;
		userData << "Calories: " << endl << " ";
	}
	userData.close();
	fileBufferVectorUpdater();
	fileUpdater();
}
void FitnessPal::findBenchPrAvgBasedOnWeight(char version) {
	int tempWeight = weight % 10;
	tempWeight = weight - tempWeight;
	for (int i = 0; i < 21; i++) {
		if (tempWeight == benchPrAvg[i][0]){
			if (version == 'A') {
				cout << benchPrAvg[i][1];
			}
			else {
				benchPR = benchPrAvg[i][1];
			}
		}
	}
}
void FitnessPal::findSquatPrAvgBasedOnWeight(char version) {
	int tempWeight = weight % 10;
	tempWeight = weight - tempWeight;
	for (int i = 0; i < 21; i++) {
		if (tempWeight == squatPrAvg[i][0]) {
			if (version == 'A') {
				cout << squatPrAvg[i][1];
			}
			else {
				squatPR = squatPrAvg[i][1];
			}
		}
	}
}
void FitnessPal::findDeadliftPrAvgBasedOnWeight(char version) {
	int tempWeight = weight % 10;
	tempWeight = weight - tempWeight;
	for (int i = 0; i < 21; i++) {
		if (tempWeight == deadLiftPrAvg[i][0]) {
			if (version == 'A') {
				cout << deadLiftPrAvg[i][1];
			}
			else {
				deadLiftPR = deadLiftPrAvg[i][1];
			}
		}
	}
}
void FitnessPal::maintenanceCalFinder() {
// using James formula for Lean Body Mass:
	int leanBodyMass;
	if (sex == 'M') {
		leanBodyMass = (1.1 * weight) - (128 * pow((weight / height), 2));
	}else{
		leanBodyMass = (1.07 * weight) - (148 * pow((weight / height), 2));
	}
	//13.8 being the calories needed to support 1 pound of lean muscle mass
	int bmr = leanBodyMass * 13.8;
	maintenanceCals = bmr * activityArray[activity-1];
	cout << "Calculated Maintenance Calories: " << maintenanceCals;
}
void FitnessPal::activityAccessor(){
	cout << "Whats your activity level? Enter: " << endl;
	cout << "1: Not active/office job(no exercize)" << endl;
	cout << "2: Light exercise(1-2days a week)" << endl;
	cout << "3: Moderate exercise(3-5days a week" << endl;
	cout << "4: Heavy exercise(6-7days a week)" << endl;
	cout << "5: Athlete(2 times a day)" << endl;
	cin >> activity;
	userData << "Activity = " << activity << endl;
}
void FitnessPal::calorieIntake() {
	char choice = 'N';
	while (choice != 'Y') {
		cout << "Enter total calories you ate for the day: " << endl;
		cin >> cals;
		cout << "You entered " << cals << " Is this correct? Enter (Y) for Yes and (N) for No: " << endl;
		cin >> choice;
	}
	if (cals > maintenanceCals) {
		cout << "This is " << cals - maintenanceCals << " more cals then your maintenance calories" << endl;
	}
	else if (cals < maintenanceCals) {
		cout << "This is " << maintenanceCals - cals << " less cals then your maintenance calories" << endl;
	}
	string temp = currentDate() + " " + to_string(cals);
	fileBufferVector.push_back(temp);
	save();
}
std::string FitnessPal::currentDate() {
#pragma warning(disable : 4996)
	time_t t = time(0);
	tm* now = localtime(&t);
	std::string date =  to_string(now->tm_mon + 1) + '/' + to_string(now->tm_mday) + '/' + to_string(now->tm_year + 1900);
	return date;
}
void FitnessPal::fileBufferVectorUpdater() {
	userData.open("UserData.txt");
	string temp;
	while(!userData.eof()){
		getline(userData, temp);
		fileBufferVector.push_back(temp);
	}
	userData.close();
}
void FitnessPal::fileUpdater() {
	for (int i = 0; i < fileBufferVector.size(); i++) {
		string temp = fileBufferVector[i];
		string temp2;
		int i2 = 0;
		while(temp.at(i2) != ' '){
			temp2 += temp.at(i2);
			i2++;
		}
		if (temp2 == "Height") {
			int pos = temp.find('=') + 2;
			height = stoi(temp.substr(pos));
		}
		if (temp2 == "Weight") {
			int pos = temp.find('=') + 2;
			weight = stoi(temp.substr(pos));
		}
		if (temp2 == "Age") {
			int pos = temp.find('=') + 2;
			age = stoi(temp.substr(pos));
		}
		if (temp2 == "Sex") {
			int pos = temp.find('=') + 2;
			sex = temp.at(pos);
		}
		if (temp2 == "Activity") {
			int pos = temp.find('=') + 2;
			activity = stoi(temp.substr(pos));
		}
		if (temp2 == "Bench") {
			int pos = temp.find('=') + 2;
			benchPR = stoi(temp.substr(pos));
		}
		if (temp2 == "Squat") {
			int pos = temp.find('=') + 2;
			squatPR = stoi(temp.substr(pos));
		}
		if (temp2 == "Dead") {
			int pos = temp.find('=') + 2;
			deadLiftPR = stoi(temp.substr(pos));
		}
	}
}
void FitnessPal::waterIntake() {
	int multipler;
	if (age < 30) {
		multipler = 40;
	}
	else if(age >= 30 && age <= 55) {
		multipler = 35;
	}
	else if (age > 55) {
		multipler = 30;
	}
	float water = ((weight/2.2) * multipler) / 28.3;
	cout << "Recommended water intake: " << water;
}
void FitnessPal::save() {
	userData.open("UserData.txt");
	for (int i = 0; i < fileBufferVector.size()-1;i++) {
		userData << fileBufferVector[i] << endl;
	}
	userData << fileBufferVector[fileBufferVector.size()-1];
	userData.close();
}