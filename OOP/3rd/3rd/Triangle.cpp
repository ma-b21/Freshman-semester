#include<iostream>
#include"Triangle.h"
using namespace std;

double C_triangle::_length()
{
	return 3 * side_length;
}
double C_triangle::_square()
{
	return (sqrt(3) / 4) * side_length * side_length;
}
void C_triangle::show()
{
	cout << "�����ε��ܳ�Ϊ" << _length() << "��" << "���Ϊ" << _square() << "��" << endl;
}