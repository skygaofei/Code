// 车站.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int a, n, m, x;
int ans;
int xs1[105] = { 0,1,1,2 }, xs2[105] = { 0,0,0,0 };
int main()
{
	scanf("%d%d%d%d", &a, &n, &m, &x);
	for (int i = 4; i < n; i++)
	{
		xs1[i] = xs1[i - 2] + xs1[i - 1] - 1;
		xs2[i] = xs2[i - 2] + xs2[i - 1] + 1;
	}
	ans = (m - a * xs1[n - 1])/xs2[n - 1];
	printf("%d", a*xs1[x] + ans * xs2[x]);
	return 0;
}
