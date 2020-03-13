// 全排列.cpp: 定义控制台应用程序的入口点。
//
#include<bits/stdc++.h>
using namespace std;
int num[10];
bool vis[10];
int n;
void print()
{
	for (int i = 1; i <= n; i++)
		printf("%5d", num[i]);
	cout << endl;
}
void dg(int s)
{
	if (s == n+1)
	{
		print();
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				vis[i] = true;
				num[s] = i;
				dg(s + 1);
				vis[i] = false;
			}
		}
	}
}
int main()
{
	cin >> n;
	dg(1);
    return 0;
}

