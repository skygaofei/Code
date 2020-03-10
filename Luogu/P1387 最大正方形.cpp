// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int a[1510][1510];
int f[1510][1510], ans = -999999999;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 0)
				continue;
			f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
			if (ans < f[i][j])
				ans = f[i][j];
		}
	cout << ans;

    return 0;
}