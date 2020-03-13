#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int inf = 111111111;
struct location
{
	int x, y;
}mp[201];
int a[201][201];
double b[201][201], dis, mx[201];
int n;
double dt(int i, int j)
{
	return sqrt(pow((mp[i].x - mp[j].x), 2) + pow((mp[i].y - mp[j].y), 2));
}
void Init()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> mp[i].x >> mp[i].y;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			scanf("%1d", &a[i][j]);
			if (i == j)
				b[i][j] = 0;
			else
				if (a[i][j] == 1)
					b[i][j] = dt(i, j);
				else
					b[i][j] = inf;
		}
}
void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (b[i][k] + b[k][j]<b[i][j])
					b[i][j] = b[i][k] + b[k][j];
}
void now()
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (mx[i]<b[i][j] && b[i][j] != inf)
				mx[i] = b[i][j];
}
double path()
{
	int i, j;
	double t = inf;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (b[i][j] == inf)
			{
				dis = dt(i, j);
				if (dis + mx[i] + mx[j]<t)
					t = dis + mx[i] + mx[j];
			}
	for (i = 1; i <= n; i++)
		if (mx[i]>t)
			t = mx[i];
	return t;
}
int main()
{
	Init();
	floyd();
	now();
	printf("%.6lf", path());
	return 0;
}
