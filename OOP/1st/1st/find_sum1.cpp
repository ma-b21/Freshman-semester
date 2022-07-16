#include"find_sum1.h"
long long find_sum1(long long n)
{
	if (n % 2 == 0)
	{
		long long x;
		x= ((n + 2) * (n / 2)) / 2;
		return x;
	}
	else
	{
		long long x;
		x= ((n + 1) * ((n - 1) / 2)) / 2;
		return x;
	}
}