#include<iostream>
#include<string>
#include<climits>
#include <queue>
#include<cmath>
using namespace std;

constexpr auto sum_state = 16384;
struct node{
	int length=INT_MAX;
	int ord=-1;
	bool check=false;
	string last_state;
};

struct compare {
	bool operator()(node a, node b)
	{
		return a.length > b.length;
	}
};

int pos[14] = { 0 },st = -1;
node minest[sum_state];
string name[14] = {"G2","A3","B3","C3","D3","E3","F3","G3","A4","B4","C4","D4","E4","F4" };

int trans(string temp)
{
	int c = 0;
	for (int i = 13; i >= 0; i--)
		c += ((temp[i] - '0') * pow(2, 13 - i));
	return c;
}

string trans_back(int num)
{
	string temp;
	temp.resize(14);
	for (int i = 0; i < 14; i++)
		temp[i] = '0';
	for (int i = 13; i >= 0; i--)
	{
		temp[i] = num % 2 + '0';
		num /= 2;
	}
	return temp;
}

int tem(int i, int j)
{
	int k = abs(pos[i] - pos[j]) + 1;
	if (k == 3) return 3;
	if (k == 6 || k == 8 || k == 10) return 4;
	if (k == 5) return 5;
	if (k == 4 || k == 12) return 6;
	if (k == 7) return 7;
	if (k == 2 || k == 14) return 8;
	return 1000;
}

int f_length(string temp)
{
	int sum = 0;
	for (int i = 0; i < 14; i++)
		if (temp[i] == '1')
			pos[sum++] = i;
	if (sum == 0 || sum == 1) return 0;
	if (sum == 2)
	{
		int k = abs(pos[0] - pos[1]) + 1;
		if (k == 3) return 3;
		if (k == 6 || k == 8 || k == 10) return 4;
		if (k == 5) return 5;
		if (k == 4 || k == 12) return 6;
		if (k == 7) return 7;
		return 1000;
	}
	else
	{
		int c = 0;
		for (int i = 0; i < sum-1; i++)
		{
			for (int j = i + 1; j < sum; j++)
			{
				c = c ^ tem(i, j);
			}
		}
		return c;
	}
}

void press(string &temp,int i)
{
	if (temp[i] == '0')
	{
		temp[i] = '1';
		return;
	}
	if (temp[i] == '1')
	{
		temp[i] = '0';
		return;
	}
}

void find_min(string state)
{
	
	for (int i = 0; i < 14; i++)
	{
		string temp ;
		temp.resize(14);
		temp = state;
		press(temp, i);
		//cout << state << "    " << temp << endl;
		int length_temp = f_length(temp) + minest[trans(state)].length;
		if (length_temp < minest[trans(temp)].length)
		{
			minest[trans(temp)].length = length_temp;
			minest[trans(temp)].last_state = state;
		}
	}
}

int main()
{
	string state;
	state.resize(15);
	cin >> state;
	string temp = state;
	for (int i = 0; i < sum_state; i++)
	{
		minest[i].check = false;
		minest[i].length = INT_MAX;
		minest[i].ord = i;
		minest[i].last_state.resize(14);
	}
	minest[trans(state)].length = 0;
	minest[trans(state)].check = true;

	while (minest[0].length == INT_MAX)
	{
		int pos = 15, mini = INT_MAX;
		find_min(temp);
		for (int i = 0; i < sum_state; i++)
		{
			if (minest[i].length != INT_MAX && !minest[i].check)
			{
				if (minest[i].length < mini)
				{
					pos = i;
					mini = minest[i].length;
				}
			}
		}
		temp = trans_back(pos);
		minest[pos].check = true;
	}

	vector<string>press_ord;
	vector<string>state_ord;
	string last = minest[0].last_state;
	string now = trans_back(0);
	state_ord.push_back(now);
	while (last != state)
	{
		for (int i = 0; i < 14; i++)
			if (last[i] != now[i])  press_ord.push_back(name[i]);
		state_ord.push_back(last);
		now = last;
		last = minest[trans(last)].last_state;
	}
	state_ord.push_back(last);
	for (int i = 0; i < 14; i++)
		if (last[i] != now[i])  press_ord.push_back(name[i]);
	for (int i = press_ord.size() - 1; i >= 0; i--)
		cout << press_ord[i] << ' ';
	cout << endl << minest[0].length << endl;

	/*for (int i = 0; i < sum_state; i++)
	{
		if (minest[i].length != INT_MAX)
			cout << minest[i].last_state<<"   " << trans_back(i) << "   " << minest[i].length << endl;
	}
	cout << endl << endl;
	for (int i = state_ord.size() - 1; i >= 0; i--)
		cout << state_ord[i] << endl;
	
	/*find_min(temp);
	for (int i = 0; i < sum_state ; i++)
	{
		
		if (minest[i].length != INT_MAX && ! minest[i].check)
		{
			node_list.push(minest[i]);
			cout << minest[i].check << ' ';
		}
	}
	cout << endl;
	while (!node_list.empty())
	{
		cout << node_list.top().length << ' ';
		node_list.pop();
	}
	cout << endl;*/
	return 0;
}