#pragma once
#include"Shape.h"

class C_triangle:public C_shape
{
public:
	C_triangle() {};
	~C_triangle(){};
	double _length();
	double _square();
	void show();
};