#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int cnum[60000];
int color[60000][16] = { 0 };
int temp[16] = { 0 };
int ord = 0;
int k = 0;
class graph
{
private:
	int n = 0;
	int m = 0;
	vector<vector<int> >side_list;
	vector<int> node_list;
public:
	graph() {};
	~graph() {};
	void read_data();
	void find_color(int num, int cnumi);
	void show_result();
};

void graph::read_data()
{
	cin >> n >> m;
	side_list.resize(n + 1);
	node_list.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int tem1 = 0, tem2 = 0;
		cin >> tem1 >> tem2;
		side_list[tem1].push_back(tem2);
		side_list[tem2].push_back(tem1);
	}	
	for (int i = 0; i < n + 1; i++)
		node_list[i] = 0;
	node_list[1] = 1;
	for (int i = 0; i < 60000; i++)
		cnum[i] = 0;
}

void graph::find_color(int num, int cnumi)
{
	if (num == n + 1) {
		for (int i = 1; i < n + 1; i++)
			color[k][i] = node_list[i];
		cnum[k++] = cnumi;
		return;
	}
	for (int i = 1; i < cnumi; i++)
	{
		bool check = false;
		for (int j = 0; j < side_list[num].size(); j++)
			if (node_list[side_list[num][j]] == i) check = true;
		if (!check)
		{
			node_list[num] = i;
			find_color(num + 1, cnumi);
			node_list[num] = 0;
		}
	}
	node_list[num] = cnumi++;
	find_color(num + 1, cnumi);
	node_list[num] = 0;


}

void graph::show_result()
{
	int mini = INT_MAX;
	int posi = 0;
	for (int i = 0; i < k; i++)
	{
		if (cnum[i] < mini)
		{
			mini = cnum[i];
			posi = i;
		}
	}
	cout << mini - 1 << endl;
	for (int i = 1; i < n + 1; i++)
		cout << color[posi][i] << ' ';
}

int main()
{
	graph G;
	G.read_data();
	G.find_color(2,2);
	G.show_result();
	return 0;
}