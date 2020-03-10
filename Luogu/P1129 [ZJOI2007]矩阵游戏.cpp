#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define maxn 405
#define re register
using namespace std;
vector<int> e[maxn * maxn];
int n, t, timemark, link[maxn * maxn];
int vis[maxn * maxn];
int cnt,x;
bool find(int x)
{
	for (re int i = 0; i < e[x].size(); ++i)
	{
		int p = e[x][i];
		if (vis[p] != timemark)
		{
			vis[p] = timemark;
			if (!link[p] || find(link[p]))
			{
				link[p] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (re int i = 1; i <= n; ++i)
			for (re int j = 1; j <= n; ++j)
			{
				scanf("%d", &x);
				if (x == 1)
					e[i].push_back(j + n);
			}
		for (re int i = 1; i <= n; ++i)
		{
			++timemark;
			if (find(i))
				++cnt;
		}
		if (cnt >= n)
			printf("Yes\n");
		else
			printf("No\n");
		memset(e, 0, sizeof(e));
		memset(link, 0, sizeof(link));
		timemark = 0;
		memset(vis, 0, sizeof(vis));
		cnt = 0;
	}
	return 0;
}