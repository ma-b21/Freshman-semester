#include<iostream>
#include"COMPUTEMAIN.h"

void RESULT_TIME::getresult()
{
	m_time.mb_getStart();
	m_sample.GETGCD();
	m_time.mb_getEnd();
	m_time.mb_report();
	m_time.mb_getStart();
	m_sample.GETLCM();
	m_time.mb_getEnd();
	m_time.mb_report();
}