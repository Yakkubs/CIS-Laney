#ifndef SPHERE_H
#define SPHERE_H
#include "POINT.H"

class Sphere {
private:

	Point center;
	double radius;

public:
	//constructors
	Sphere(Point x, float y);
	Sphere(float z);
	//functions
	Point getCenter();
	float getRadius();
	float getVolume();
	float getSurfaceArea();
};

#endif