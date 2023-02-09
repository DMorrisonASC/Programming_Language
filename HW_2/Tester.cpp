#include "Point.h"
#include<cstdio>

void changeX_cord (Point* item, int num);
// Allocate 2 Point objects on the heap (don't forget to delete them)
Point* tempTip1(int x, int y);
Point* tempTip2(int x, int y);


int main() {
	Point dot(1,2);
	Point circle(4,8);
	Point * ref_circle; 
	ref_circle = &circle;
	// Allocate 2 Point objects on the heap (don't forget to delete them)
	// Point* tip1 = tempTip(7,3);
	
	// print distance between "dot" and "circle" Point objects.
	printf("%f", dot.dis(dot, circle));
	
	changeX_cord( &circle, 19);
	printf("\n%d", circle.getX());
	// Test if "ref_circle" correctly recieved the address of "circle"
	// printf("\n%p", ref_circle);
	// printf("\n%p", &circle);
	
}

void changeX_cord (Point* ref, int num) {
	// item = new Point(4,8);
	// int new_cordX = item.getX() + num;
	// item.setX(new_cordX);
	// Point item = ref;
	Point *item = ref;
	int new_cordX = item->getX() + num;
	item->setX(new_cordX);
	// printf("\n%d", item.getX());
	// printf("\n%d", new_cordX);
}

// Point* tempTip(int x, int y){
	// Point* tip1;
	// pTwo = new Point(x,y);
	// std::cout << tip1;
	// std::cout<<"\n\n";
	// std::cout<< tip1->getX();
	// std::cout<<"\n\n";
	// return tip1;
	// delete tip1;
// }
