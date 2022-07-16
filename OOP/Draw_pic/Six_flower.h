#pragma once
class flower
{
private:
	int center_x;
	int center_y;
	double in_sidelength;
public:
	flower(int i = 0, int j = 0, int k = 0) :in_sidelength(i), center_x(j), center_y(k) {};
	~flower() {};
	void Draw_flower(CDC* pDC);
	POINT* find_point();
};