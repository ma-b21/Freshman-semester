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
	cout << "Բ�ε��ܳ�Ϊ" << _length() << "��" << "���Ϊ" << _square() << "��" << endl;
}