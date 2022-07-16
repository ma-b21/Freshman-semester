#include "string_in.h"
#include <iostream>

string_in::string_in()
{
	cout << "请输入数据：";
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
			cout << "字符串首位非数字" << endl;
		}
		catch (char)
		{
			cout << "字符串末位非数字" << endl;
		}
		catch (string)
		{
			cout << "字符串中非首位含有非'.'且非数字的字符" << endl;
		}
		catch (bool)
		{
			cout << "字符串中非首位含有超过一个'.'字符" << endl;
		}
		catch (float)
		{
			cout << "字符串表示数字为浮点值" << endl;
		}
	}
}
