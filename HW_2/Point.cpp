#include "Point.h"
#include<iostream>
#include<cmath>

/* Point::Point(int xVal, int yVal):x(xVal), y(yVal) {
	x = xVal;
	y = yVal;
}
*/

Point::Point(int xVal, int yVal) {
	x = xVal;
	y = yVal;
}

int Point::getX() const{
	return x;
}

int Point::getY() const{
	return y;
}

void Point::setX(int xNew) {
	x = xNew;
}

void Point::setY(int yNew) {
	y = yNew;
}

double Point::dis(Point a, Point b) {
	// int x = a.getX() + getX();
	int abso_Xa = abs(a.getX());
	int abso_Xb = abs(b.getX());
	// Get y-cords
	int abso_Ya = abs(a.getY());
	int abso_Yb = abs(b.getY());
	// Calculate distance between two points
	double distance = sqrt( pow(abso_Xb - abso_Xa, 2) + pow(abso_Yb - abso_Ya, 2) );
	
	return distance;
	
}
