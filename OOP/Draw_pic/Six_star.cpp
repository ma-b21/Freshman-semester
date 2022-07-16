#include"pch.h"
#include"Six_star.h"
#include<cmath>
void Six_star::Draw_star(CDC*pDC)//以(x,y)为中心的五角星
{
	int length = this->side_length;
	int x = this->center_x;
	int y = this->center_y;

	pDC->MoveTo(x, y-length/sqrt(3));
	pDC->LineTo(x - length / 2, y + length / (2 * sqrt(3)));
	pDC->LineTo(x + length / 2, y + length / (2 * sqrt(3)));
	pDC->LineTo(x, y - length / sqrt(3));//上三角
	
	pDC->MoveTo(x, y + length / sqrt(3));
	pDC->LineTo(x - length / 2, y - length / (2 * sqrt(3)));
	pDC->LineTo(x + length / 2, y - length / (2 * sqrt(3)));
	pDC->LineTo(x, y + length / sqrt(3));//下三角
	
}

POINT* Six_star::find_node()
{
	int x = this->center_x;
	int y = this->center_y;
	double length = this->side_length;
	POINT node[6] = { 0 };
	node[0] = { (long)x, (long)(y - length / sqrt(3)) };
	node[1] = { (long)(x - length / 2),(long)(y + length / (2 * sqrt(3))) };
	node[2] = { (long)(x + length / 2),(long)(y + length / (2 * sqrt(3))) };
	node[3] = { (long)x, (long)(y + length / sqrt(3)) };
	node[4] = { (long)(x - length / 2),(long)(y - length / (2 * sqrt(3))) };
	node[5] = { (long)(x + length / 2), (long)(y - length / (2 * sqrt(3))) };
	return node;
	return node;
}
