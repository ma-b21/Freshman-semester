#include"run.h"
#include"date.h"
#include<iostream>
using namespace std;

void date_run::run()
{
	date a; int n;
	a.set_date(2022, 3, 15);
	cout << "������";
	a.show_date();
	cout << "������һ������n�����������n�������:";
	cin >> n;
	a.compute_date(n);
	cout << n << "�����";
	a.show_date();
}