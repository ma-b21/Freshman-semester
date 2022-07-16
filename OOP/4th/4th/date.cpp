#include"date.h"
#include <iostream>
using namespace std;

void date::set_date(int i,int j,int k)
{
	year = i;
	month = j;
	day = k;
}

void date::show_date()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}

bool date::Is_leap()//判断是否是闰年
{
	if (year % 4 != 0) return false;
	if (year % 100 == 0 && year % 400 != 0) return false;
	return true;
}
void date::compute_date(int n)
{
	if (n == 0) return;
	if (n > 0)
	{
		if (Is_leap())
		{
			if (day + n <= day2[month])
			{
				day += n;
				return;
			}
			if (day + n > day2[month])
			{
				n += (day - day2[month]-1);
				day = 1;
				if (month == 12)
				{
					month = 1;
					year += 1;
				}
				else month += 1;
				compute_date(n);
				return;
			}
		}
		else
		{
			if (day + n <= day1[month])
			{
				day += n;
				return;
			}
			if (day + n > day1[month])
			{
				n += (day - day1[month]-1);
				day = 1;
				if (month == 12)
				{
					month = 1;
					year += 1;
				}
				else month += 1;
				compute_date(n);
				return;
			}
		}
	}
	if (n < 0)
	{
		n = -n;
		if (n < day)
		{
			day -= n;
			return;
		}
		if (n >= day)
		{
			n -= day;
			n = -n;
			if (month >= 2) month -= 1;
			else 
			{
				month = 12;
				year -= 1;
			}
			if (Is_leap()) day = day2[month];
			else day = day1[month];
			compute_date(n);
			return;
		}
	}
}