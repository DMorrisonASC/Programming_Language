#include "Point.h"
#include<cstdio>

void changeX_cord (Point& item, int num);

int main() {
	Point dot(1,2);
	Point circle(4,8);
	Point * ref_circle; 
	ref_circle = &circle;
	
	// printf(dot.dis(dot, circle));
	printf("%f", dot.dis(dot, circle));
	
	// changeX_cord(ref_circle, 1);
	printf("\n%d", circle.getX());
	
	// printf("\n%f", ref_circle);
	// Test if "ref_circle" correctly recieved the address of "circle"
	// printf("\n%p", ref_circle);
	// printf("\n%p", &circle);
	
}

void changeX_cord (Point& ref, int num) {
	// item = new Point(4,8);
	// int new_cordX = item.getX() + num;
	// item.setX(new_cordX);
	Point item = ref;
	int new_cordX = item.getX() + num;
	item.setX(new_cordX);
	
}
