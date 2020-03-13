// 奶酪.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <ctime>
#include <iomanip>
#define ll long long
using namespace std;
int fa[1005], up[100005], down[100005], t, n, h;
int find(int x)
{
	return x != fa[x] ? fa[x] = find(fa[x]) : fa[x];
}
double cal_dis(ll x, ll y, ll z, ll _x, ll _y, ll _z)
{
	return sqrt((x - _x)*(x - _x) + (y - _y)*(y - _y) + (z - _z)*(z - _z));
}
ll x[100005], y[100005], z[100005], r;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%lld", &n, &h, &r);
		int counter1 = 0, counter2 = 0;
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
			if (z[i] + r >= h)
			{
				counter1++;
				up[counter1] = i;
			}
			if (z[i] - r <= 0)
			{
				counter2++;
				down[counter2] = i;
			}
			for (int j = 1; j <= i; j++)
			{
				if (cal_dis(x[i], y[i], z[i], x[j], y[j], z[j]) <= 2 * r)
				{
					int a1 = find(i), a2 = find(j);
					if (a1 != a2)
						fa[a1] = a2;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= counter1; i++)
		{
			for (int j = 1; j <= counter2; j++)
				if (find(up[i]) == find(down[j]))
				{
					cnt = 1;
					break;
				}
			if (cnt)
				break;
		}
		if (cnt)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

