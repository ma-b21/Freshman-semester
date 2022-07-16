#include"find_sum.h"

long long find_sum(long long n)
{
	long long sum = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i % 2 == 0) 
			sum += i;
	}
	return sum;
}
