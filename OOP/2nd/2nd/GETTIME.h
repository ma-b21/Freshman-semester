#pragma once
#include<iostream>
using namespace std;

class Retime
{
private:
	clock_t m_timeStart, m_timeEnd;
public:
    Retime();
    ~Retime() { }
    void mb_getStart();
    void mb_getEnd();
    void mb_report();
};