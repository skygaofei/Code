#include<iostream>
#include<algorithm>
using namespace std;
int f[1510][1510];
int a[1510][1510];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> f[i][j];
			if (i % 2 == 1 && j % 2 == 0)
				f[i][j] = !f[i][j];
			if (i % 2 == 0 && j % 2 == 1)
				f[i][j] = !f[i][j];
			a[i][j] = 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (f[i][j] == f[i - 1][j] && f[i][j] == f[i][j - 1] && f[i][j] == f[i - 1][j - 1])
				a[i][j] = min(min(a[i - 1][j], a[i][j - 1]), a[i - 1][j - 1]) + 1;
		}
	int ans = -99999999;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (ans < a[i][j])
				ans = a[i][j];
	cout << ans;
    return 0;
}

