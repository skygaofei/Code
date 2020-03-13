// 梦中的统计.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;

int m, n;
int num[10];

void com(int x)
{
	while (x != 0)
	{
		num[x % 10]++;
		x /= 10;
	}
}

int main()
{
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		com(i);
	}
	for (int i = 0; i < 10; i++)
		cout << num[i] << ' ';
    return 0;
}

