#include"Square.h"
#include<iostream>
using namespace std;

double C_square::_length()
{
	return 4 * side_length;
}

double C_square::_square()
{
	return side_length * side_length;
}

void C_square::show()
{
	cout << "�����ε��ܳ�Ϊ" << _length() << "��" << "���Ϊ" << _square() << "��" << endl;
}