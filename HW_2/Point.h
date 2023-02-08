#pragma once

class Point {
	private:
		int x, y;
	public:
		Point(int xVal, int yVal);
		int getX() const;
		int getY() const;
		void setX(int xNew);
		void setY(int yNew);
		double dis(Point, Point);
	
	
};