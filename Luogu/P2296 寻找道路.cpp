// 寻找道路.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#define maxn 10010
#define maxm 200010
using namespace std;
int point[maxn], nex[maxm], to[maxm], cnt, val[maxn];
int pointa[maxn], nexa[maxm], toa[maxm], cnt1;
int s, t;
bool vis[maxn], vis1[maxn], flag[maxn];
int n, m;

void addedge(int x, int y)
{
	nex[++cnt] = point[x];
	to[cnt] = y;
	point[x] = cnt;
}

void add(int x, int y)
{
	nexa[++cnt1] = pointa[x];
	toa[cnt1] = y;
	pointa[x] = cnt1;
}

int que[maxn];

void find(int x)
{
	int l = 1,r = 1;
	que[l] = x;
	r++;
	vis1[t] = true;
	while (l < r)
	{
		for (int i = pointa[que[l]]; i; i = nexa[i])
		{
			if (!vis1[toa[i]])
			{
				vis1[toa[i]] = true;
				que[r] = toa[i];
				r++;
			}
		}
		l++;
	}
}


int l, r;


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		addedge(x, y);
		add(y, x);
	}
	cin >> s >> t;
	find(t);
	for (int x = 1; x <= n; x++)
	{
		flag[x] = true;
		for (int i = point[x]; i; i = nex[i])
			if (!vis1[to[i]])
				flag[x] = false;

	}
	l = 1; r = 1;
	que[l] = s;
	r++;
	while (l < r)
	{
		for (int i = point[que[l]]; i; i = nex[i])
		{
			if (!vis[to[i]]&&flag[to[i]])
			{
				que[r] = to[i];
				r++;
				vis[to[i]] = 1;
				val[to[i]] = val[que[l]] + 1;
			}
		}
		l++;
	}

	if (val[t])
		cout << val[t];
	else
		cout << -1;
    return 0;
}