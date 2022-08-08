#include<iostream>
#include<climits>
using namespace std;
int n, l, z = 1, num = 1; int k = 0;
int l_min = INT_MAX;
int node[325][19] = { 0 }; int node_ord = 1;//数组存点
int side_length[19] = { 0 };
struct side {
	int x;
	int y;
	int w;
	int c;
}q[325] = { 0 }, p[325] = { 0 }, r[326][19] = { 0 };//p为总边集，q为已选边集，r为最短道路边集

void sort()
{
	int oop = n * (n - 1);
	for (int k = 0; k < oop; k++)
	{
		for (int i = 1; i < oop; i++)
		{
			for (int j = i + 1; j < oop + 1; j++)
				if (p[i].w > p[j].w) swap(p[i], p[j]);
		}
	}
}//按边长排序

int find(int pos)
{
	for (int i = 1; i < n; i++)
		if (q[i].x == pos) return q[i].y;
	return -1;
}

bool Can_be_road()
{
	int mark_st[19] = { 0 }; int mark_end[19] = { 0 };
	for (int i = 1; i < num; i++)
	{
		mark_st[q[i].x]++;
		mark_end[q[i].y]++;
	}

	for (int i = 1; i < n + 1; i++)
		if (mark_st[i] > 1 || mark_end[i] > 1) return false;

	return true;
}//每取一个点判断是否能成道路。

bool Is_road()
{
	int pos = 0; int node_tem[19] = { 0 };
	int mark_st[19] = { 0 }; int mark_end[19] = { 0 };
	for (int i = 1; i < num; i++)
	{
		mark_st[q[i].x]++;
		mark_end[q[i].y]++;
	}

	for (int i = 1; i < n + 1; i++)
		if (mark_st[i] == 1 && mark_end[i] == 0)
		{
			pos = i;
			break;
		}
	if (pos == 0) return false;
	node_tem[1] = pos;
	for (int i = 2; i < n + 1; i++)
	{
		node_tem[i] = find(node_tem[i - 1]);
		for (int j = 1; j < i; j++)
			if (node_tem[j] == node_tem[i]) return false;
	}
	return true;
}

void find_road(int ord)
{
	if (num == n)
	{
		if (Is_road())
		{ 
			/*k++;
			for (int i = 1; i < num; i++)
				cout << q[i].w << '(' << q[i].x << ',' << q[i].y << ')' << q[i].c << " ";
			cout << endl;*/
			int l_tem = 0, m_tem = 0;
			for (int i = 1; i < num; i++)
			{
				l_tem += q[i].w;
				m_tem += q[i].c;
			}
			if (l_tem == l_min)
			{
				if (m_tem <= l)
				{
					z++;
					for (int j = 1; j < n; j++)
						r[z][j] = q[j];
					r[z][0].w = l_min;
				}
			}
			if (l_tem < l_min)
			{
				if (m_tem <= l)
				{
					for (int j = 1; j < n; j++)
						r[z][j] = q[j];
					l_min = l_tem;
					r[z][0].w = l_tem;
				}
			}
		}
		return;
	}
	for (int i = ord; i < n * (n - 1) + 1; i++)
	{
		q[num++] = p[i];
		if (!Can_be_road())
		{
			num--;
			continue;
		}
		int l_tem = 0, m_tem = 0;
		for (int j = 1; j < num; j++)
		{
			l_tem += q[j].w;
			m_tem += q[j].c;
		}
		for (int j = i + 1; j <= i + n - num && j < (n - 1) * n + 1; j++)
			l_tem += p[j].w;
		if (l_tem > l_min)
		{
			num--;
			return;
		}
		if (m_tem <= l)find_road(i + 1);
		num--;
	}

}

void find_node(int st, int row)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (r[row][j].x == r[row][st].y)
			{
				node[row][node_ord++] = r[row][j].x;
				node[row][node_ord] = r[row][j].y;
				find_node(j, row);
				return;
			}
		}
	}
}

int cmp_dictionary(int a[19], int b[19])
{
	for (int i = 1; i < n + 1; i++)
	{
		if (a[i] > b[i]) return false;
		if (a[i] < b[i]) return true;
	}
}

void show()
{
	if (l_min == INT_MAX)
	{
		cout << -1 << endl;
		return;
	}
	cout << l_min << endl;
	for (int k = 1; k <= z; k++)
	{
		int mark[19] = { 0 }, st = 0;
		for (int i = 1; i < n; i++)
		{
			mark[r[k][i].x]++;
			mark[r[k][i].y]++;
		}
		for (int i = 1; i < n; i++)
		{
			if (mark[r[k][i].x] == 1)
			{
				st = i;//找到起点
				break;
			}
		}
		node[k][node_ord++] = r[k][st].x;
		find_node(st, k);
		node_ord = 1;
	}
	if (z == 1 || (z > 1 && r[z][0].w < r[z - 1][0].w))
	{
		for (int i = 1; i < n + 1; i++)
			cout << node[z][i] << ' ';
	}
	else
	{
		int pos = 1;
		for (int j = 2; j <= z; j++)
			if (!cmp_dictionary(node[pos], node[j])) pos = j;
		for (int i = 1; i < n + 1; i++)
			cout << node[pos][i] << ' ';
	}
}
int main()
{
	cin >> n >> l;
	int cnone = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i != j)
			{
				p[z].x = i;
				p[z].y = j;
				cin >> p[z++].w;
			}
			else cin >> cnone;
		}
	}z = 1;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i != j) cin >> p[z++].c;
			else  cin >> cnone;
		}
	}z = 1;
	sort();
	find_road(1);
	show();
	/*for (int j = 1; j <= z; j++)
	{
		for (int i = 1; i < n; i++)
		{
			cout << r[z][i].x << ' ' << r[z][i].y << '|';
		}
		cout << endl;
	}
	for (int i = 1; i < z + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
			cout << node[i][j] << ' ';
		cout << endl;
	}*/
	//cout << endl << k;
	return 0;
}