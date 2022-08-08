#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
int k = 0;
long long result[5010];

bool check[3010];
struct node {
	int x = 0;//num
	int y = 0;//last
};

struct side {
	int st = 0;
	int ed = 0;
	long long w = 0;
};

struct dis {
	int st = 0;
	long long w = 0;
};
class graph
{
private:
	int n;
	side news;
	long long sum = 0;
	long long maxi = 0;
	vector<node>node_list;
	vector<dis>lowcost;
	vector<side>side_in;
	vector<vector<dis> >side_n;
	vector<side>side_in_circle;
public:
	int q;
public:
	graph() {
		cin >> n >> q;
		node tem;
		node_list.push_back(tem);
	}
	~graph() {}
	void read_data();
	void find_tree();
	void update_lowcost(int num);
	void change_side();
	void DFS(int str,bool check[3010]);
	//void show_data();
};

void graph::read_data()
{
	for (int i = 1; i < n + 1; i++)
	{
		node temp;
		cin >> temp.x >> temp.y;
		node_list.push_back(temp);
		/*for (int j = 1; j <= i; j++)
		{
			long long tem = pow(abs(node_list[i].x - node_list[j].x), 3) + pow(abs(node_list[i].y - node_list[j].y), 3);
			side_data[i][j] = tem;
			side_data[j][i] = tem;
		}*/
	}
	lowcost.push_back({ 0 });
	for (int i = 1; i < n + 1; i++)
	{
		long long tem = pow(abs(node_list[i].x - node_list[1].x), 3) + pow(abs(node_list[i].y - node_list[1].y), 3);
		lowcost.push_back({ 1,tem });
	}
}


void graph::find_tree()
{
	/*lowcost.push_back({0});
	for (int i = 1; i < n + 1; i++)
		lowcost.push_back({ 1,side_data[1][i] });*/
	while (side_in.size() != n-1)
	{
		int posi = 0;
		long long mini = LLONG_MAX;
		for (int i = 1; i < n + 1; i++)
		{
			if (lowcost[i].w < mini && lowcost[i].w != 0)
			{
				posi = i;
				mini = lowcost[i].w;
			}
		}
		//maxi = max(maxi, mini);
		sum += mini;
		side tempr;
		tempr.st = lowcost[posi].st;
		tempr.ed = posi;
		tempr.w = lowcost[posi].w;
		side_in.push_back(tempr);
		lowcost[posi].w = 0;
		this->update_lowcost(posi);
	}
	//cout << sum << endl;
	result[k++] = sum;
	
	side_n.resize(n + 1);//side_n是当前树的邻接表
	for (int i = 0; i < side_in.size(); i++)
	{
		side_n[side_in[i].st].push_back({ side_in[i].ed,side_in[i].w });
		side_n[side_in[i].ed].push_back({ side_in[i].st,side_in[i].w });//构造邻接表
	}
}

void graph::update_lowcost(int num)
{
	for (int i = 1; i < n + 1; i++)
	{
		if(lowcost[i].w != 0)
		{
			long long a = abs(node_list[i].x - node_list[num].x);
			long long b = abs(node_list[i].y - node_list[num].y);
			long long tem = pow(a, 3) + pow(b, 3);
			if (tem < lowcost[i].w)
			{
				lowcost[i].w = tem;
				lowcost[i].st = num;
			}
		}
	}
}

void graph::change_side()
{
	cin >> news.st >> news.ed >> news.w;//news是添加的新边
	for (int i = 0; i < side_in.size(); i++)
	{
		if ((news.st == side_in[i].st && news.ed == side_in[i].ed) || (news.st == side_in[i].ed && news.ed == side_in[i].st))
		{
			sum -= side_in[i].w;
			side_in[i].w = min(news.w, side_in[i].w);
			sum += side_in[i].w;
			result[k++] = sum;
			//side_n.clear();
			if(side_in[i].w==news.w)
			{for (int j = 0; j < side_n[news.st].size(); j++)
			{
				if (side_n[news.st][j].st == news.ed)
				{
					side_n[news.st][j].w = news.w;
					break;
				}
			}
			for (int j = 0; j < side_n[news.ed].size(); j++)
			{
				if (side_n[news.ed][j].st == news.st)
				{
					side_n[news.ed][j].w = news.w;
					break;
				}
			}}
			return;
		}//新边在树上
	}
	
	for (int i = 0; i < n + 1; i++)
		check[i] = false;
	DFS(news.st, check);//找到一条从新边起点到新边终点的道路，因为此时边不在树上，因此道路长度大于一
																		//加新边构成回路
	//道路中的边存在side_in_circle中
	long long maxm = 0;//side_in_circle中边长最大值
	int posi = 0;//side_in_circle中边长最大值出现的位置
	for (int i = 0; i < side_in_circle.size(); i++)
	{
		if (side_in_circle[i].w >= maxm)
		{
			posi = i;
			maxm = side_in_circle[i].w;
		}
	}
	if (maxm <= news.w)//新边边长最大，保留原树
	{
		result[k++] = sum;
		side_in_circle.clear();
		//side_n.clear();
		return;
	}
	for (int i = side_in.size()-1; i >=0; i--)
	{
		if ((side_in[i].st == side_in_circle[posi].st && side_in[i].ed == side_in_circle[posi].ed) || (side_in[i].st == side_in_circle[posi].ed && side_in[i].ed == side_in_circle[posi].st))
		{
			posi = i;
			break;
		}	
	}//在当前树中找出将被删去的那条边
	side tem3 = side_in[posi];
	vector<dis>::iterator it = side_n[tem3.ed].begin();
	for (; it < side_n[tem3.ed].end(); it++)
	{
		if (it->st == tem3.st)
		{
			side_n[tem3.ed].erase(it);
			break;
		}
	}
	vector<dis>::iterator ite = side_n[tem3.st].begin();
	for (; ite < side_n[tem3.st].end(); ite++)
	{
		if (ite->st == tem3.ed)
		{
			side_n[tem3.st].erase(ite);
			break;
		}
	}
	side_in[posi] = news;
	sum -= maxm;
	sum += news.w;
	result[k++] = sum;
	side_in_circle.clear();
	dis tem1 = { news.ed, news.w };
	dis tem2 = { news.st, news.w };
	side_n[news.st].push_back(tem1);
	side_n[news.ed].push_back(tem2);
	
}

void graph::DFS(int str, bool check[3010])
{
	if (str == news.ed) {
		check[0] = true;
		return;
	}
	check[str] = true;
	for (int i = 0; i < side_n[str].size(); i++)
	{
		side temp;
		temp.st = str;
		temp.ed = side_n[str][i].st;
		temp.w = side_n[str][i].w;
		side_in_circle.push_back(temp);
		if (!check[side_n[str][i].st])
			DFS(side_n[str][i].st,check);
		if (check[0]) return;
		if (side_in_circle.size() > 0) side_in_circle.pop_back();
	}
	
}



int main()
{
	graph G;
	G.read_data();
	G.find_tree();
	for (int i = 0; i < G.q; i++)
	{
		G.change_side();
		//G.show_data();
	}
	for (int i = 0; i < k; i++)
		cout << result[i] << endl;

	return 0;
}