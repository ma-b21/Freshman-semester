#include "string_in.h"
#include <iostream>

string_in::string_in()
{
	cout << "���������ݣ�";
	getline(cin, data);
}

void string_in::get_intnum()
{
	try
	{
		for (int i = 1; i < data.size(); i++)
			if (data[i] < '0' || data[i]>'9')
				throw false;
		if (data[0] == '+' || data[0] == '-' || (data[0]>'0' && data[0] < '9'))
			throw 1;
		throw false;
	}
	catch(int)
	{
		cout << stoll(data);
	}
	catch (bool)
	{
		try
		{
			if (data[0] < '0' || data[0]>'9') throw 1;
			if (data[data.size() - 1] < '0' || data[data.size() - 1]>'9') throw 'c';
			for (int i = 0; i < data.size(); i++)
				if ((data[i] > '9' || data[i] < '0') && data[i] != '.')
				{
					string a= "other mark";
					throw a;
				}
			int dotnum = 0;
			for (int i = 1; i < data.size(); i++)
				if (data[i] == '.') dotnum++;
			if (dotnum > 1) throw false;
			else {
				float a(0);
				throw a;
			}
				
		}
		catch(int)
		{
			cout << "�ַ�����λ������" << endl;
		}
		catch (char)
		{
			cout << "�ַ���ĩλ������" << endl;
		}
		catch (string)
		{
			cout << "�ַ����з���λ���з�'.'�ҷ����ֵ��ַ�" << endl;
		}
		catch (bool)
		{
			cout << "�ַ����з���λ���г���һ��'.'�ַ�" << endl;
		}
		catch (float)
		{
			cout << "�ַ�����ʾ����Ϊ����ֵ" << endl;
		}
	}
}
