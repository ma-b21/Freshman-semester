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
		cout << "请输入指令" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 0:
			{
				cout << "图形总个数为" << sum << "个" << endl;
				cout << "图形总周长为" << sum_length <<  endl;
				cout << "图形总面积为" << sum_square <<  endl;
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
			default:cout << "请输入正确指令！" << endl; break;
		}

	}
	return 0;
}