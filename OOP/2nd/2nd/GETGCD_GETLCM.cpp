#include<iostream>
#include"GETGCD_GETLCM.h"
using namespace std;

SAMPLE::SAMPLE()
{
	cout << "请输入两个整数：" << endl;
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
	cout << input1 << "和" << input2 << "的最大公约数为" << b <<"。" << endl;
	GCD = b;
}
void SAMPLE::GETLCM()
{
	int k = input1 * input2;
	cout << input1 << "和" << input2 << "的最小公倍数为" << k / GCD <<"。" << endl;
}