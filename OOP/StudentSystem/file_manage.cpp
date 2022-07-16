#include "file_manage.h"
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
void manage_system::read_data()
{
	string filename;
	cout << "�����뵼��ɼ����ļ���:";
	cin >> filename;
	ifstream fin(filename);
	if (!fin) 
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	cout << "������ϣ�" << endl << endl;
}

void manage_system::add_data()
{
	cout << "������ѧ�����Ӧ�ɼ����Կո������ÿ��һλ,����������0��" << endl;
	while (1)
	{
		student temp;
		cin >> temp.number;
		if (temp.number == 0) break;
		cin >> temp.grade;
		S.push_back(temp);
	}
	cout << "�����ϣ�" << endl << endl;
}

void manage_system::delete_by_num()
{
	long long tem{ 0 };
	cout << "��������ɾ����ѧ�ţ�";
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
	cout << "ɾ����ϣ�" << endl << endl;
}

void manage_system::delete_all()
{
	cout << "ȷ��Ҫȫ�������(y/n)" << endl;
	char s(0);
	s = _getch();
	if (s == 'y') {
		S.clear();
		cout << "ɾ����ϣ�" << endl << endl;
	}
	else
		cout << "ȡ��ɾ����" << endl << endl;
}

void manage_system::change_data()
{
	student temp;
	cout << "���������޸ĳɼ���ѧ�ż��޸ĺ�ĳɼ����Կո������";
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
	cout << "�޸ĳɹ���" << endl << endl;
}

void manage_system::search_by_num()
{
	long long tem{ 0 };
	cout << "���������ѯ��ѧ�ţ�";
	cin >> tem;
	vector<student>::iterator its;
	for (its = S.begin(); its <= S.end(); its++)
	{
		if (its->number == tem)
		{
			cout << "���ѯ��ѧ���ɼ�Ϊ��" << its->grade << endl;
			break;
		}
	}
	cout << "��ѯ������" << endl << endl;
}

void manage_system::show_all()
{
	if (S.size() == 0) 
	{
		cout << "Ŀǰ����û��Ԫ�أ�" << endl;
		cout << endl;
		return;
	}
	cout << "������ѧ����ɼ�����:" << endl;
	vector<student>::iterator its;
	for (its = S.begin(); its < S.end(); its++)
		cout << its->number << "  " << its->grade << endl;
	cout << endl;
}

void manage_system::save_data()
{
	string filename;
	cout << "�����뵼���ɼ����ļ�����";
	cin >> filename;
	ofstream fout(filename);
	if (!fout) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	vector<student>::iterator its;
	for (its = S.begin(); its < S.end(); its++)
		fout << its->number << "  " << its->grade << endl;
	fout.close();
	cout << "������ϣ�" << endl << endl;
}
