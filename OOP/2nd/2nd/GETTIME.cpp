#include<iostream>
#include<iomanip>
#include"GETTIME.h"
using namespace std;

Retime::Retime()
{
	m_timeStart = clock();
	m_timeEnd = m_timeStart;
}

void Retime::mb_getStart()
{
	m_timeStart = clock();
}
void Retime::mb_getEnd()
{
	m_timeEnd = clock();
}
void Retime::mb_report()
{
	clock_t d = m_timeEnd - m_timeStart;
	double r = (double)(d) / (double)CLOCKS_PER_SEC;
	if (r >= 1)
		cout << "��������ʱ����" << r << "�롣" << endl;
	else cout<<setw(4) << "��������ʱ����" << d << "���롣" << endl;

}