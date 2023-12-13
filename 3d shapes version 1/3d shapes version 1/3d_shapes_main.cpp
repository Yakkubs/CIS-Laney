#include <iostream>
#include "Point.h"
#include "Sphere.h"
using namespace std;

int main() {
	Point myPoint; //create a Point with default values
	Point myOtherPoint(1, 2, 3); //create a point with given values

	cout << myPoint.getX() << endl; //get the x value from myPoint
	cout << myOtherPoint.getY() << endl; //get y from myOtherPoint

	Sphere mySphere(myOtherPoint, 2);
	Sphere myOtherSphere(1);

	cout << mySphere.getSurfaceArea();

	return 0;
}
