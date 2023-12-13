#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H
#include <fstream>

using namespace std;

const int SIZE = 1000;

class CommonAlg2 {
private:
	int* array;
	int* tempArray;
	int size = SIZE;
public:
	//constructor
	CommonAlg2();
	//methods
	void method1();
	int method2();
	void method3();
	void method4();
	void method5(int guess);
	void method6();
	void method7();
	void method8();
	void method9();
	void method10();
	void method11NoPrint();
	void method11();
	void method12();
	void method13();
	void method14();
	~CommonAlg2();
};
#endif