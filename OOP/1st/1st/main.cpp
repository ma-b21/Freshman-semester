#include<iostream>
#include"find_sum.h"
#include"find_sum1.h"
using namespace std;

int main()
{
	long long a;
	for (a = 0; a <= 100000000; a++)
	{
		cout << find_sum(a) << endl;
		cout << find_sum1(a) << endl;
	}
	return 0;
}