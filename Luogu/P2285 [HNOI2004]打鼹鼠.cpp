// 打鼹鼠.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
using namespace std;
int f[10005], n, m;
int x[10005], y[10005], tim[10005];
int ans = -0x3f3f3f3f;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d",&tim[i],&x[i], &y[i]);
		f[i] = 1;
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = i - 1; j >= 1; j--)
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= tim[i] - tim[j])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}

