// 哥达巴赫猜想.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
bool zs(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x%i == 0)
			return 0;
	return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 4; i <= n; i += 2)
	{
		for (int j = 2; j <= i; j++)
		{
			if (zs(j) && zs(i - j))
			{
				printf("%d=%d+%d\n", i, j, i - j); 
				break;
			}
		}
	}
	return 0;
}

