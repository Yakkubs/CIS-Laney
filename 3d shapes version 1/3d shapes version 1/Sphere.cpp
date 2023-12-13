#include "Sphere.h"
#include "Point.h"
#include <cmath>

using namespace std;

const float PI = 3.14159;

Sphere::Sphere(Point x, float y) {
	center = x;
	radius = y;
}

Sphere::Sphere(float x) {
	radius = x;
	center = Point(0, 0, 0);
}

Point Sphere::getCenter() {
	Point tempCenter = center;
	return tempCenter;
}

float Sphere::getRadius() {
	float tempRadius = radius;
	return tempRadius;
}

float Sphere::getVolume() {
	float volume = (4 * PI *pow(radius, 3))/3;
	return volume;
}
float Sphere::getSurfaceArea() {
	float surfaceArea = 4 * PI * pow(radius, 2);
	return surfaceArea;
}