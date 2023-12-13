#include <iostream>
#include <string>

using namespace std;

void getDate(int* dayPtr, int* monthPtr, int* yearPtr) {
    string date;
    int day, month, year;
    cout << "Please enter the date in the formatt dd-mm-yyyy (for example, 24-10-2017) " << endl;
    cin >> date;

    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(4, 2));
    year = stoi(date.substr(7, 4));

    *dayPtr = day;
    *monthPtr = month;
    *yearPtr = year;
}

int main(){
    int day;
    int month;
    int year;
    getDate(&day, &month, &year);

    cout << day << " " << month << " " << year;
}