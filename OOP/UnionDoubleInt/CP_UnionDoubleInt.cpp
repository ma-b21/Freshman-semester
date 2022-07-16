#include <iostream>
#include<iomanip>
using namespace std;
#include "CP_UnionDoubleInt.h"
int k = 0;
void gb_showDoubleIntBinMemory(const U_DoubleInt& u)
{
    cout << fixed << setprecision(8) << u.m_double;
    cout << "在内存当中存储的数据是0b";
    gb_binaryInt(u.m_LLong);
    cout  << endl;
} // 函数gb_showFloatIntHexMemory定义结束

void gb_testDoubleInt()
{
    U_DoubleInt u(0.0);
    u.m_double = 0.0 / u.m_double; // 得到非数
    gb_showDoubleIntBinMemory(u);
} // 函数gb_testFloatInt定义结束

void gb_binaryInt(unsigned long long n)
{
    char a;
    a = n % 2 + '0';
    n = n>>1;
    if (n == 0)
        ;
    else
        gb_binaryInt(n);
    if ((k % 4 == 0) && (k != 0))
        cout << ' ';
    k++;
    cout<<a;
}