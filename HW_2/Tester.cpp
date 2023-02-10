#include "Point.h"
#include<cstdio>
#include <iostream>

void changeX_cord (Point* item, int num);
void changeX_cord (Point item, int num);

int main() {
	// Allocate 2 Point objects on the heap (don't forget to delete them)
	Point * tempPointer;
	Point * tempPointer2;
	//
	Point dot(1,2);
	Point circle(4,8);
	Point * ref_circle; 
	ref_circle = &circle;
	
	// print distance between "dot" and "circle" Point objects.
	printf("%f", dot.dis(dot, circle));
	
	changeX_cord(ref_circle, 19);
	changeX_cord(circle, 19);
	printf("\n%d\n", circle.getX());
	
	// Test if "ref_circle" correctly recieved the address of "circle"
	// printf("\n%p", ref_circle);
	// printf("\n%p", &circle);
	
	delete tempPointer;
	delete tempPointer2;
	
	// 4) Make an array of Points and use pointers to access them. 
	// Make sure that you call at least 
	// 2 methods in a loop that access all elements of the array.
	int numOfPoints = 5;
	Point p[numOfPoints];
	
	for (int i = 0; i < numOfPoints; i++ ) {
		p[i].setX(i);
		p[i].setY(i);
	}
	
	for (int i = 0; i < numOfPoints; i++) {
		// print distance between each point
		// printf("\n%f", dot.dis(dot, circle));
		if ( i < numOfPoints - 1) {
		std::cout << "\nThis distance between " << "("
		<< p[i].getX() << ", " << p[i].getY() << ")" 
		<< " & " 
		<< "(" << p[i+1].getX() << ", " << p[i+1].getY() << ")" 
		<< " is " 
		<< p[i].dis(p[i], p[i+1]) << std::endl;
		}
	}
}
// pass by reference
void changeX_cord (Point* ref, int num) {
	Point * item = ref;
	int new_cordX = item->getX() + num;
	item->setX(new_cordX);
}
// pass by value
void changeX_cord (Point ref, int num) {
	
	int new_cordX = ref.getX() + num;
	ref.setX(new_cordX);
}
