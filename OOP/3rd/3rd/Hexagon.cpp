#include"Hexagon.h"
#include<iostream>
using namespace std;

double C_hexagon::_length()
{
	return 6 * side_length;
}
double C_hexagon::_square()
{
	return 6* (sqrt(3) / 4) * side_length * side_length;
}
void C_hexagon::show()
{
	cout << "�����ε��ܳ�Ϊ" << _length() << "��" << "���Ϊ" << _square() << "��" << endl;
}