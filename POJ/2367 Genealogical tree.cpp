// Genealogical tree.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int point[1010], nex[1010], to[1010], val[1010], cnt;


void add(int x, int y)
{
	nex[++cnt] = point[x];
	to[cnt] = y;
	val[y]++;
	point[x] = cnt;
}

int que[1010];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int p;
		while (cin >> p)
		{
			if (p == 0)
				break;
			else
				add(i, p);
		}
	}
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++)
	{
		if (val[i] == 0)
		{
			que[r] = i;
			r++;
		}
	}
	while (l < r)
	{
		int x = que[l];
		l++;
		for (int i = point[x]; i; i = nex[i])
		{
			val[to[i]]--;
			if (val[to[i]] == 0)
			{
				que[r] = to[i];
				r++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << que[i] << ' ';
    return 0;
}