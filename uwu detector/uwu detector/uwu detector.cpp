#include <iostream>
#include <string>

using namespace std;

void uwuSenpai() {
	string uwu;
	int uwutimes = 0;

	cout << "Enter a line of text: ";
	cin >> uwu;
	for (unsigned int i = 0; i < uwu.length(); i++) {
		for (unsigned int j = 2; j < uwu.length(); j++) {

			if ((uwu.at(i) == 'u' && uwu.at(j) == 'u' )|| (uwu.at(i) == 'U' && uwu.at(j) == 'U') || (uwu.at(i) == 'u' && uwu.at(j) == 'U') || (uwu.at(i) == 'U' && uwu.at(j) == 'u')) {
				
				for (unsigned int k = i; k < ((uwu.length() - i)); k++) {
					
					if (uwu.at(k) == 'w' || uwu.at(k) == 'W') {
						uwutimes++;
					}
				}
			}
		}
	}

	cout << "Number of uwus in this line:\t" << uwutimes;

}

int main(){

	uwuSenpai();

}
