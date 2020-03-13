// Likecloud-吃、吃、吃.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
int map[205][205];
int book[205][205];
int sx, sy;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	sx = n; sy = m / 2 + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			book[i][j] = max(max(book[i - 1][j], book[i - 1][j - 1]), book[i - 1][j + 1]) + map[i][j];
	printf("%d", max(max(book[sx][sy], book[sx][sy - 1]), book[sx][sy + 1]));
	return 0;
}

