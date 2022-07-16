#include<iostream>
#include"CP_IntByString.h"
using namespace std;

int main()
{
	CP_IntByString a,b;
	a.mb_setValue("-0");
	b.mb_setValue("+0");
	CP_IntByString c = a-b;
	c.mb_show("Result is:");
	
	return 0;
}