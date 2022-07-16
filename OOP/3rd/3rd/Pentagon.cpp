#include"Pentagon.h"
#include<cmath>
#include<iostream>
using namespace std;

constexpr auto PI = 3.14;
double C_pentagon::_length()
{
	return 5 * side_length;
}

double C_pentagon::_square()
{
	double s= (5 * side_length * side_length * tan(((double)54/360) * 2 * PI)) / 4;
	return s;
}

void C_pentagon::show()
{
	cout << "五边形的周长为" << _length() << "，" << "面积为" << _square() << "。" << endl;
}