// 吃奶酪.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define re register
using namespace std;
int n;
double x[100], y[100], dis[100][100];
double ans = 99999999999.0;
bool vis[20];
double culdis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
void dfs(int index, int pos, double len)
{
	if (len > ans)
		return;
	if (index == n)
	{
		ans = min(ans, len);
		return;
	}
	for(int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i] = true;
			dfs(index + 1, i, len + dis[pos][i]);
			vis[i] = false;
		}
}
int main()
{
	scanf("%d", &n);
	for (re int i = 1; i <= n; i++)
		scanf("%lf%lf", &x[i], &y[i]);
	x[0] = 0, y[0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dis[i][j] = culdis(x[i], y[i], x[j], y[j]);
	dfs(0, 0, 0.00);
	printf("%.2lf", ans);
	return 0;
}
