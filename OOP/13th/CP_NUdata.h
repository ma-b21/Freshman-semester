#pragma once
#include<iostream>
#include<vector>
#include"CP_Product.h"
using namespace std;

class NUdata :public Product
{
public:
	 void Add_Student(vector<CP_Student> &delec);
	 virtual void Add_Student(CP_Student s, CP_ChainDoubleLink* p){};
	 virtual void Delete_By_num(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec){};
	 virtual void Delete_By_score(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec){};
	 virtual void Find_By_num(CP_Student s, CP_ChainDoubleLink* p){};
	 virtual void Show_all();
	 virtual void Show_By_score(CP_Student s, CP_ChainDoubleLink* p){};
};
