#include"run.h"
#include"date.h"
#include<iostream>
using namespace std;

void date_run::run()
{
	date a; int n;
	a.set_date(2022, 3, 15);
	cout << "现在是";
	a.show_date();
	cout << "请输入一个整数n，程序会计算出n天后日期:";
	cin >> n;
	a.compute_date(n);
	cout << n << "天后是";
	a.show_date();
}