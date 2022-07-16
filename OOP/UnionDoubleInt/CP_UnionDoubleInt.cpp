#include <iostream>
#include<iomanip>
using namespace std;
#include "CP_UnionDoubleInt.h"
int k = 0;
void gb_showDoubleIntBinMemory(const U_DoubleInt& u)
{
    cout << fixed << setprecision(8) << u.m_double;
    cout << "���ڴ浱�д洢��������0b";
    gb_binaryInt(u.m_LLong);
    cout  << endl;
} // ����gb_showFloatIntHexMemory�������

void gb_testDoubleInt()
{
    U_DoubleInt u(0.0);
    u.m_double = 0.0 / u.m_double; // �õ�����
    gb_showDoubleIntBinMemory(u);
} // ����gb_testFloatInt�������

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