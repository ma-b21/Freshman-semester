#include <iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

struct node {
	long maxm = 0;
	long now = 0;
	int direc = -1;
	long pro = 0;
};

struct side {
	int ed = 0;
	long cap = 0;
	long flow = 0;
};

class graph
{
private:
	int n = 0;
	int m = 0;
	int result = 0;
	vector<node>node_list;
	vector<vector<side> >side_list;
	vector<vector<side> >side_n;
public:
	graph();
	~graph() {};
	void show();
	bool find_road();
	void add_sum(int num, int plus);
	void solve();
};

graph::graph()
{
	cin >> n >> m;
	node_list.resize(n + 2);
	side_list.resize(n + 2);
	side_n.resize(n + 2);
	for (int i = 0; i < n + 2; i++)
		side_list[i].resize(n + 2);
	for (int i = 0; i < n + 1; i++)
		cin >> node_list[i].maxm;
	node_list[n + 1].maxm = LONG_MAX;
	for (int i = 0; i < m; i++)
	{
		int x = 0, y = 0, w = 0;
		cin >> x >> y >> w;
		side_list[x][y].ed = y;
		if (side_list[x][y].cap == LONG_MAX) continue;
		if (w < 0) 	side_list[x][y].cap = LONG_MAX;
		else  side_list[x][y].cap += w;
	}
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (side_list[i][j].cap != 0)
				side_n[i].push_back(side_list[i][j]);
		}
	}
}

void graph::show()
{
	cout << result << endl;
}

bool graph::find_road()
{
	node_list[0].pro = LONG_MAX;
	node_list[0].direc = -2;
	queue<int> temp;
	temp.push(0);
	while (!temp.empty())
	{
		int num = temp.front();
		for (int i = 0; i < side_n[num].size(); i++)
		{
			if ((side_n[num][i].cap > side_n[num][i].flow) && (node_list[side_n[num][i].ed].direc == -1) && (node_list[side_n[num][i].ed].maxm > node_list[side_n[num][i].ed].now))
			{
				temp.push(side_n[num][i].ed);
				node_list[side_n[num][i].ed].direc = num;
				node_list[side_n[num][i].ed].pro = min(node_list[num].pro, (side_n[num][i].cap - side_n[num][i].flow));
				if (side_n[num][i].ed != n + 1) node_list[side_n[num][i].ed].pro = min(node_list[side_n[num][i].ed].pro, (node_list[side_n[num][i].ed].maxm - node_list[side_n[num][i].ed].now));
				if (side_n[num][i].ed == n + 1)
				{
					add_sum(n + 1, node_list[n + 1].pro);
					node_list[0].now += node_list[n + 1].pro;
					return true;
				}
			}
		}
		temp.pop();
	}
	return false;
}

void graph::add_sum(int num, int plus)
{
	if (num == 0) return;
	int k = node_list[num].direc;
	node_list[num].now += plus;
	for (int j = 0; j < side_n[k].size(); j++)
	{
		if (side_n[k][j].ed == num)
		{
			side_n[k][j].flow += plus;
			break;
		}
	}
	add_sum(k, plus);
}

void graph::solve()
{
	while (find_road())
	{
		for (int i = 1; i < n + 2; i++)
		{
			node_list[i].direc = -1;
			node_list[i].pro = 0;
		}
		if (node_list[0].now >= node_list[0].maxm)
		{
			result = node_list[0].maxm;
			return;
		}
	}
	result = node_list[n+1].now;
}


int main()
{
	graph G;
	G.solve();
	G.show();
	return 0;
}