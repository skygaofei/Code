// 合唱队形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, a[105], f[105], _f[105],answer;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
	for (int i = n; i >= 1; i--)
		for (int j = n + 1; j > i; j--)
			if (a[i] > a[j])
				_f[i] = max(_f[i], _f[j] + 1);
	for (int i = 1; i <= n; i++)
		answer = max(f[i] + _f[i] - 1, answer);
	printf("%d", n - answer);
   	return 0;
}

