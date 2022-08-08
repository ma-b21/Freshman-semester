#include <iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<iomanip>
#include<queue>
using namespace std;

int n;
struct step {
	int ord;
	double amount;
};
vector< vector<step> >ahead_ord;
vector< vector<int> >back_node;
double* product_speed = new double[110000];//记录各条产线的生产速率
double* construct_speed = new double[110000];//记录每条产线建设时间
double* minest_time = new double[110000];//记录到每一步的最短时间
queue< vector<step> >temp_ord;
int dim[110000] = { 0 }; bool ad[110000] = { false };

double find_minTime(int a, int b)
{
	double sum_amount = ahead_ord[a][b].amount;
	double p_speed = product_speed[ahead_ord[a][b].ord];
	double c_speed = construct_speed[ahead_ord[a][b].ord];
	double temp_time = 0; int pos=-1;
	for (int i = 1; ; i++)
	{
		double tem = (((i + 1.0) * i) / 2) * c_speed * p_speed;
		if (tem > sum_amount)
		{
			pos = i - 1;
			temp_time = (sum_amount - (((pos + 1.0) * pos) / 2) * p_speed * c_speed) / (i * p_speed) + pos * c_speed;
			break;
		}
		if (tem == sum_amount)
		{
			pos = i;
			temp_time = pos * c_speed;
			break;
		}
	}
	return temp_time;
}

void find_minest()
{
	for (int i = 1; i < n + 1; i++)
	{
		int num = ahead_ord[i].size();
		if (num != 1)
		{
			double maxi = 0;
			for (int j = 1; j < num; j++)
				maxi = max(maxi, minest_time[ahead_ord[i][j].ord] + find_minTime(i, j));
			minest_time[ahead_ord[i][0].ord] = maxi;
		}
		else minest_time[ahead_ord[i][0].ord] = 0;
	}
}

void remark(int i)
{
	temp_ord.push(ahead_ord[i]);
	ad[i] = true;
	for (int j = 0; j < back_node[i].size(); j++)
	{
		dim[back_node[i][j]]--;
		if (dim[back_node[i][j]] == 0 && !ad[back_node[i][j]])  remark(back_node[i][j]);
	}
	return;
}

int main()
{
	cin >> n;
	back_node.resize(n + 1);
	for (int i = 1; i < n; i++)
	{
		cin >> product_speed[i];
		minest_time[i] = 0;
	}minest_time[n] = 0;
	for (int i = 1; i < n; i++)
		cin >> construct_speed[i];

	ahead_ord.push_back({ });
	for (int i = 1; i < n + 1; i++)
	{
		int num = 0;
		ahead_ord.push_back({ });
		ahead_ord[i].push_back({ i,0 });
		cin >> num;
		dim[i] = num;
		for (int j = 1; j < num + 1; j++)
		{
			int ord = -1; double amount = -1.0;
			cin >> ord >> amount;
			back_node[ord].push_back(i);
			ahead_ord[i].push_back({ ord,amount });
		}
	}
	//remark();

	for (int i = 1; i < n + 1; i++)
	{
		if (dim[i] == 0 && !ad[i])
			remark(i);
	}
	int pos = 1;
	while (!temp_ord.empty())
	{
		ahead_ord[pos++] = temp_ord.front();
		temp_ord.pop();
	}
	
	
	find_minest();
	cout << setprecision(2) << fixed << minest_time[n] << endl;
	
	/*for (int i = 1; i < n + 1; i++)
	{
		cout << ahead_ord[i][0].ord << ' ';
		for (int j = 1; j < ahead_ord[i].size(); j++)
			cout << ahead_ord[i][j].ord << ' ';
		cout << endl;
	}*/
	

	
	return 0;
}

