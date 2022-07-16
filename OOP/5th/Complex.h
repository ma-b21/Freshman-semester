#pragma once
#include<iostream>
using namespace std;
class C_complex
{
public:
	double real;
	double imaginary;
public:
	C_complex(double r = 0, double i = 0) :real(r), imaginary(i) {};
	~C_complex() {};
	friend ostream& operator <<(ostream& out, C_complex& c);
	friend istream& operator >>(istream& in, C_complex& c);
};

extern C_complex& operator ++ (C_complex& c);//前缀加
extern C_complex operator ++ (C_complex& c, int);//后缀加
extern C_complex& operator -- (C_complex& c);//前缀减
extern C_complex operator -- (C_complex& c, int);//后缀减
extern C_complex operator +(C_complex& a, C_complex& b);
extern C_complex operator -(C_complex& a, C_complex& b);
extern C_complex operator *(C_complex& a, C_complex& b);
extern C_complex operator /(C_complex& a, C_complex& b);
extern C_complex operator +=(C_complex& a, C_complex& b);//a=a+b
extern C_complex operator -=(C_complex& a, C_complex& b);//a=a-b;
extern C_complex operator *=(C_complex& a, C_complex& b);//a=a*b;
extern C_complex operator /=(C_complex& a, C_complex& b);//a=a/b;
extern bool operator ==(C_complex& a, C_complex& b);//a=b?