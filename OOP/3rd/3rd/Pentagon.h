#pragma once
#include"Shape.h"

class C_pentagon:public C_shape
{
public:
	C_pentagon(){};
	~C_pentagon() {};
	double _length();
	double _square();
	void show();
};