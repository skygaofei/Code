// 组合数问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 2000
using namespace std;
int c[2005][2005], n, m, t, k;
int f[2005][2005];
void pre()
{
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	c[1][1] = 1;
	for (int i = 0; i <= maxn; i++)
		c[i][0] = 1;
	for (int i = 2; i <= maxn; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
	for (int i = 2; i <= maxn; i++)
	{
		for (int j = 1; j <= i; j++)
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (c[i][j] == 0);
		f[i][i + 1] = f[i][i];
	}
}
int main()
{
	scanf("%d%d", &t, &k);
	pre();
	while (t--)
	{
		scanf("%d%d", &n, &m);
		if (m > n)
			m = n;
		printf("%d\n",f[n][m]);
	}
	return 0;
}

