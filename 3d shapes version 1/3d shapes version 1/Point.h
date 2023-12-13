#ifndef POINT_H
#define POINT_H

class Point{
private:
	double xCoord, yCoord, zCoord;

public:
//constructors
	Point(float float_1, float float_2, float float_3);
	Point();
//functions
	double getX();
	double getY();
	double getZ();
	void setX(double x);
	void setY(double y);
	void setZ(double z);
};
#endif
