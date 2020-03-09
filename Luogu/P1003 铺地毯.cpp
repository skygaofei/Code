// 铺地毯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n;
struct ditan
{
	int a, b, g, k;
}p[10005];
int x, y;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &p[i].a, &p[i].b, &p[i].g, &p[i].k);
	scanf("%d%d", &x, &y);
	for(int i=n;i>=1;i--)
		if (p[i].a<=x&&p[i].g+p[i].a>=x&&p[i].b<=y&&p[i].b+p[i].k>=y)
		{
			printf("%d", i);
			return 0;
		}
	printf("-1");
	return 0;
}