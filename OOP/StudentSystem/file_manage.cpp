#include "file_manage.h"
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
void manage_system::read_data()
{
	string filename;
	cout << "请输入导入成绩的文件名:";
	cin >> filename;
	ifstream fin(filename);
	if (!fin) 
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	while (1)
	{
		student temp;
		fin >> temp.number;
		if (temp.number == 0) break;
		fin >> temp.grade;
		S.push_back(temp);
	}
	fin.close();
	cout << "导入完毕！" << endl << endl;
}

void manage_system::add_data()
{
	cout << "请输入学号与对应成绩，以空格隔开，每行一位,结束请输入0：" << endl;
	while (1)
	{
		student temp;
		cin >> temp.number;
		if (temp.number == 0) break;
		cin >> temp.grade;
		S.push_back(temp);
	}
	cout << "添加完毕！" << endl << endl;
}

void manage_system::delete_by_num()
{
	long long tem{ 0 };
	cout << "请输入想删除的学号：";
	cin >> tem;
	vector<student>::iterator its;
	for (its = S.begin(); its <= S.end(); its++)
	{
		if (its->number == tem)
		{
			S.erase(its);
			break;
		}
	}
	cout << "删除完毕！" << endl << endl;
}

void manage_system::delete_all()
{
	cout << "确定要全部清空吗？(y/n)" << endl;
	char s(0);
	s = _getch();
	if (s == 'y') {
		S.clear();
		cout << "删除完毕！" << endl << endl;
	}
	else
		cout << "取消删除！" << endl << endl;
}

void manage_system::change_data()
{
	student temp;
	cout << "请输入想修改成绩的学号及修改后的成绩，以空格隔开：";
	cin >> temp.number>>temp.grade;
	vector<student>::iterator its;
	for (its = S.begin(); its <= S.end(); its++)
	{
		if (its->number == temp.number)
		{
			its->grade = temp.grade;
			break;
		}
	}
	cout << "修改成功！" << endl << endl;
}

void manage_system::search_by_num()
{
	long long tem{ 0 };
	cout << "请输入想查询的学号：";
	cin >> tem;
	vector<student>::iterator its;
	for (its = S.begin(); its <= S.end(); its++)
	{
		if (its->number == tem)
		{
			cout << "你查询的学生成绩为：" << its->grade << endl;
			break;
		}
	}
	cout << "查询结束！" << endl << endl;
}

void manage_system::show_all()
{
	if (S.size() == 0) 
	{
		cout << "目前表单中没有元素！" << endl;
		cout << endl;
		return;
	}
	cout << "所有人学号与成绩如下:" << endl;
	vector<student>::iterator its;
	for (its = S.begin(); its < S.end(); its++)
		cout << its->number << "  " << its->grade << endl;
	cout << endl;
}

void manage_system::save_data()
{
	string filename;
	cout << "请输入导出成绩的文件名：";
	cin >> filename;
	ofstream fout(filename);
	if (!fout) {
		cout << "文件打开失败！" << endl;
		return;
	}
	vector<student>::iterator its;
	for (its = S.begin(); its < S.end(); its++)
		fout << its->number << "  " << its->grade << endl;
	fout.close();
	cout << "导出完毕！" << endl << endl;
}
