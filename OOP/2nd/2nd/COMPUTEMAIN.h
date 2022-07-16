#pragma once
#include<iostream>
#include"GETGCD_GETLCM.h"
#include"GETTIME.h"
using namespace std;

class RESULT_TIME
{
public:
	Retime m_time;
	SAMPLE m_sample;
public:
	RESULT_TIME() {};
	~RESULT_TIME() {};
	void getresult();
};