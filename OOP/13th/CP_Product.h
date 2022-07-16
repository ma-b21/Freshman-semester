#pragma once
#include"CP_ChainDoubleLink.h"
#include<iostream>
#include<vector>
using namespace std;

class Product
{
public:
	CP_ChainDoubleLink* m_head;
	Product() :m_head(NULL) {};
	virtual void Add_Student(CP_Student s, CP_ChainDoubleLink* p) = 0;
	virtual void Delete_By_num(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec) = 0;
	virtual void Delete_By_score(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec) = 0;
	virtual void Find_By_num(CP_Student s, CP_ChainDoubleLink* p) = 0;
	virtual void Show_all() = 0;
	virtual void Show_By_score(CP_Student s, CP_ChainDoubleLink* p) = 0;
};