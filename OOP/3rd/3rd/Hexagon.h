#pragma once
#include"Shape.h"

class C_hexagon:public C_shape
{
public:
	C_hexagon()  {};
	~C_hexagon() {};
	double _length();
	double _square();
	void show();
};