#pragma once

class Circle
{
private:
	int center_x;
	int center_y;
	double radius;
public:
	Circle(int i = 0, int j = 0, int k = 0) :radius(i), center_x(j), center_y(k) {};
	~Circle() {};
	void Draw_circle(CDC*pDC);
};