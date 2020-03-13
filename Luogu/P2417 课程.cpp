#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define maxn 20005
#define re register
using namespace std;
vector<int> son[305];
int vis[maxn], link[maxn];
int n, m, p, timemark,ans;
bool find(int x)
{
	for (re int i = 0; i < son[x].size(); ++i)
	{
		int p = son[x][i];
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
	int t,tmp;
	scanf("%d", &t);
	while (t--)
	{
		memset(link, 0, sizeof(link));
		memset(vis, 0, sizeof(vis));
		memset(son, 0, sizeof(son));
		timemark = 1;
		scanf("%d%d", &p, &n);
		for (re int i = 1; i <= p; ++i)
		{
			scanf("%d", &m);
			for (re int j = 1; j <= m; ++j)
				scanf("%d",&tmp), son[i].push_back(tmp);
		}
		if (p > n)
		{
			printf("NO\n");
			continue;
		}
		ans = 0;
		for (re int i = 1; i <= p; ++i)
		{
			timemark++;
			if (find(i))
				ans++;
		}
		if (ans == p)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}