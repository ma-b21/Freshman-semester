#include<iostream>
#include"Triangle.h"
#include"Square.h"
#include"Hexagon.h"
#include"Pentagon.h"
#include"Circle.h"
using namespace std;


int main()
{
	double sum_length = 0;
	double sum_square = 0;
	int sum = 0; bool check = true;
	while (check)
	{
		cout << "������ָ��" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 0:
			{
				cout << "ͼ���ܸ���Ϊ" << sum << "��" << endl;
				cout << "ͼ�����ܳ�Ϊ" << sum_length <<  endl;
				cout << "ͼ�������Ϊ" << sum_square <<  endl;
				check = false;
			}break;
			case 1:
			{
				C_triangle oop;
				oop.show();
				sum_length += oop._length();
				sum_square += oop._square();
				sum++;
			}break;
			case 2:
			{
				C_square oop;
				oop.show();
				sum_length += oop._length();
				sum_square += oop._square();
				sum++;
			}break;
			case 3:
			{
				C_pentagon oop;
				oop.show();
				sum_length += oop._length();
				sum_square += oop._square();
				sum++;
			}break;
			case 4:
			{
				C_hexagon oop;
				oop.show();
				sum_length += oop._length();
				sum_square += oop._square();
				sum++;
			}break;
			case 5:
			{
				C_circle oop;
				oop.show();
				sum_length += oop._length();
				sum_square += oop._square();
				sum++;
			}break;
			default:cout << "��������ȷָ�" << endl; break;
		}

	}
	return 0;
}