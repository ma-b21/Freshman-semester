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
		std::cout << "请输入需要排序的数字，以空格隔开，以回车结束：" << endl;
		T input{};
		while (cin >> input)
		{
			mydata.push_back(input);
			if (cin.get() == '\n') break;
		}
	};
	~Csort() {
		cout << "排序结束！" << endl;
	};
	void sort_bySort() {
		T* a = &mydata[0];
		T* b = &mydata[mydata.size()-1]+1;
		sort(a, b);
		cout << "经过sort函数排序之后结果为：" << endl;
		for (int i = 0; i < mydata.size(); i++)
			cout << mydata[i] << ' ';
		cout << endl;
	};
	void sort_bySet() {
		set <long long> s(mydata.begin(), mydata.end());
		set <long long> ::iterator it;

		cout << "经过set容器排序之后结果为：" << endl;
		for (it = s.begin(); it != s.end(); it++)
			cout << *(it) << ' ';
		cout << endl;
	};
};
