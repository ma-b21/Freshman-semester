#pragma once
#include"Shape.h"

class C_circle:public C_shape
{
public:
	C_circle()  {};
	~C_circle() {};
	double _length();
	double _square();
	void show();
};