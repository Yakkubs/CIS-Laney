#include "Point.h"
using namespace std;

Point::Point(float float_1, float float_2, float float_3) {

	xCoord = float_1;
	yCoord = float_2;
	zCoord = float_3;
}

Point::Point() {

	xCoord = 0;
	yCoord = 0;
	zCoord = 0;
}

double Point::getX() {
	return xCoord;
}

double Point::getY() {
	return yCoord;
}

double Point::getZ() {
	return zCoord;
}

void Point::setX(double new_x){
	xCoord = new_x;
}

void Point::setY(double new_y) {
	yCoord = new_y;
}

void Point::setZ(double new_z) {
	zCoord = new_z;
}