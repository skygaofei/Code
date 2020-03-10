// Fair Game.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<algorithm>
using namespace std;
int a[110];
int maxn;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
		maxn = max(x, maxn);
	}
	int s = 0;
	int an;
	for (int i = 1; i <= maxn; i++)
	{
		if (a[i] != 0)
			s++;
		if (i != maxn && a[i] != 0)
			an = i;
	}
	if (s > 2)
		cout << "NO";
	else if (a[maxn] != n / 2)
		cout << "NO";
	else
		cout << "YES" << endl << an << " " << maxn;
    return 0;
}

