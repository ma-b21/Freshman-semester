#include<iostream>
#include"GETGCD_GETLCM.h"
using namespace std;

SAMPLE::SAMPLE()
{
	cout << "����������������" << endl;
	cin >> input1 >> input2;
	GCD = 0;
}
void SAMPLE::GETGCD()
{
	int a = input1;
	int b = input2;
	while (1)
	{
		a %= b;
		if (a == 0) break;
		swap( a, b);
	}
	cout << input1 << "��" << input2 << "�����Լ��Ϊ" << b <<"��" << endl;
	GCD = b;
}
void SAMPLE::GETLCM()
{
	int k = input1 * input2;
	cout << input1 << "��" << input2 << "����С������Ϊ" << k / GCD <<"��" << endl;
}