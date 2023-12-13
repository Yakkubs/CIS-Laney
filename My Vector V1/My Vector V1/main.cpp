#include <iostream>
#include "MyVector.h"
#include <string>

using namespace std;

int main(){
	MyVector<int> vec(4);
	vec.insert(1);
	vec.insert(2);
	vec.insert(3);
	vec.insert(4);
	vec.insert(5);
	//vec.remove(4);
	vec = vec + 4;
	//vec[1] = 4;
	//cout << vec[1];
	cout << vec;
}