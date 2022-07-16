#pragma once
class Six_star
{
private:
	double side_length;
	int center_x;
	int center_y;
public:
	Six_star(int i=0,int j=0,int k=0) :side_length(i), center_x(j), center_y(k) {};
	~Six_star() {};
	void Draw_star(CDC*pDC);
	POINT* find_node();
};