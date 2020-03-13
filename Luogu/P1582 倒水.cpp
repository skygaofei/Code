// luogu-judger-enable-o2
// 倒水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n, k, answer;
int counter(int n)
{
	int number = 0;
	for (n; n; n -= n & -n)
		number++;
	return number;
}
int main()
{
	scanf("%d%d", &n, &k);
	while (counter(n) > k)
	{
		answer += n & -n;
		n += n & -n;
	}
	printf("%d", answer);
	return 0;
}