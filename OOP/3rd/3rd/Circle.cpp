#include<iostream>
#include"Circle.h"
using namespace std;
constexpr auto PI = 3.1415926535;
double C_circle::_length()
{
	return 2 * PI * side_length;
}

double C_circle::_square()
{
	return PI * side_length * side_length;
}

void C_circle::show()
{
	cout << "圆形的周长为" << _length() << "，" << "面积为" << _square() << "。" << endl;
}