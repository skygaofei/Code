#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[40][40];
int ans = 1;
int main()
{
	int x = 0, y = 0;
	int n;
	cin >> n;
	a[1][n / 2 + 1] = ans;
	x = 1; y = n / 2 + 1;
	ans++;
	for (int i = 2; i <= n*n; i++)
	{
		if (x == 1 && y != n)
		{
			a[n][y + 1] = ans;
			ans++;
			x = n;
			y = y + 1;
		}
		else if (y == n&&x != 1)
		{
			a[x - 1][1] = ans;
			ans++;
			x = x - 1;
			y = 1;
		}
		else if (x == 1 && y == n)
		{
			a[x + 1][y] = ans;
			ans++;
			x = x + 1;
		}
		else if (x != 1 && y != n&&a[x - 1][y + 1] == 0)
		{
			a[x - 1][y + 1] = ans;
			ans++;
			x = x - 1;
			y = y + 1;
		}
		else if (x != 1 && y != n)
		{
			a[x + 1][y] = ans;
			ans++;
			x = x + 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}