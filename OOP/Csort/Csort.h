#pragma once
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
template<typename T>
class Csort
{
public:
	vector<T>mydata;
public:
	Csort() {
		std::cout << "��������Ҫ��������֣��Կո�������Իس�������" << endl;
		T input{};
		while (cin >> input)
		{
			mydata.push_back(input);
			if (cin.get() == '\n') break;
		}
	};
	~Csort() {
		cout << "���������" << endl;
	};
	void sort_bySort() {
		T* a = &mydata[0];
		T* b = &mydata[mydata.size()-1]+1;
		sort(a, b);
		cout << "����sort��������֮����Ϊ��" << endl;
		for (int i = 0; i < mydata.size(); i++)
			cout << mydata[i] << ' ';
		cout << endl;
	};
	void sort_bySet() {
		set <long long> s(mydata.begin(), mydata.end());
		set <long long> ::iterator it;

		cout << "����set��������֮����Ϊ��" << endl;
		for (it = s.begin(); it != s.end(); it++)
			cout << *(it) << ' ';
		cout << endl;
	};
};
