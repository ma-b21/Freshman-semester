#pragma once
#include"Shape.h"

class C_square:public C_shape 
{
public:
	C_square() {};
	~C_square() {};
	double _length();
	double _square();
	void show();
};