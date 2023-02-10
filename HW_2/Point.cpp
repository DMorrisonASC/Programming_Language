#include "Point.h"
#include<iostream>
#include<cmath>

// One way of creating a constructer
/* Point::Point(int xVal, int yVal):x(xVal), y(yVal) {
	x = xVal;
	y = yVal;
}
*/

Point::Point(int xVal, int yVal) {
	x = xVal;
	y = yVal;
}

Point::Point() {
	x = 0;
	y = 0;
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

// Calculate the distance between two points.
// We can obtain the mathematical distance
// definition from the Euclidean 
// distance formula for a two-dimensional plane:
// d=√((x2 – x1)² + (y2 – y1)²)
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

bool Point::operator==(const Point & other) const {
	return (this -> getX() == other.getX() && this->getY() == other.getY());	
}

// Only use if 
const Point Point::operator+(const Point & other) const {
	Point result;
	result.setX(x + other.getX());
	result.setY(y + other.getY());
	// Return the values of the object
	return result;
	
}

// use -> with points 
