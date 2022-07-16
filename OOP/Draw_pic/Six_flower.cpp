
#include"pch.h"
#include "Six_flower.h"


void flower::Draw_flower(CDC* pDC)
{
	int x = this->center_x;
	int y = this->center_y;
	double length = this->in_sidelength;
	pDC->MoveTo(x + length / 2, y + length / (2 * sqrt(3)));
	pDC->AngleArc(x + length / sqrt(3), y, length / (2 * sqrt(3)), -90, 180);//ÓÒ
	pDC->AngleArc(x + length / 4, y - (3 * length) / (4 * sqrt(3)), length / (2 * sqrt(3)), -30, 180);
	//ÓÒÉÏ
	pDC->AngleArc(x - length / 4, y - (3 * length) / (4 * sqrt(3)), length / (2 * sqrt(3)), 30, 180);
	//×óÉÏ
	pDC->AngleArc(x - length / sqrt(3), y, length / (2 * sqrt(3)), 90, 180);//×ó
	pDC->AngleArc(x - length / 4, y + (3 * length) / (4 * sqrt(3)), length / (2 * sqrt(3)), 150, 180);
	//×óÏÂ
	pDC->AngleArc(x + length / 4, y + (3 * length) / (4 * sqrt(3)), length / (2 * sqrt(3)), -150, 180);

}

POINT* flower::find_point()
{
	int x = this->center_x;
	int y = this->center_y;
	double length = this->in_sidelength;
	POINT node[6] = { 0 };
	node[0] = { (long)x, (long)(y - length / sqrt(3)) };
	node[1] = { (long)(x - length / 2),(long)(y + length / (2 * sqrt(3))) };
	node[2] = {(long)( x + length / 2),(long)( y + length / (2 * sqrt(3))) };
	node[3] = { (long)x, (long)(y + length / sqrt(3)) };
	node[4] = {(long)( x - length / 2),(long)( y - length / (2 * sqrt(3))) };
	node[5] = {(long)( x + length / 2), (long)(y - length / (2 * sqrt(3))) };
	return node;
}
