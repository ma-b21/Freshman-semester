#pragma once
#include"CP_Product.h"

class Udata :public Product
{
public:
	virtual void Add_Student(CP_Student s, CP_ChainDoubleLink* p);
	virtual void Delete_By_num(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec);
	virtual void Delete_By_score(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec);
	virtual void Find_By_num(CP_Student s, CP_ChainDoubleLink* p);
	virtual void Show_all();
	virtual void Show_By_score(CP_Student s, CP_ChainDoubleLink* p);
};
