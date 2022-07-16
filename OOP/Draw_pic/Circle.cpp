#include"pch.h"
#include"Circle.h"

void Circle::Draw_circle(CDC* pDC)
{
	int x = this->center_x;
	int y = this->center_y;
	double r = this->radius;
	pDC->Ellipse(x - r , y - r, x + r, y + r);
}