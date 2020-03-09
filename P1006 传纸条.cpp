// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int f[55][55][55][55], a[55][55];
int maxx(int a, int b, int c, int d)
{
	int max = -999999999;
	if (max < d)
		max = d;
	if (max < c)
		max = c;
	if (max < b)
		max = b;
	if (max < a)
		max = a;
	return max;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int l = 1; l <= n; l++)
				for (int p = 1; p <= m; p++)
				{
					if (i == l && j == p)
						f[i][j][l][p] = -9999999999;
					else
						f[i][j][l][p] = maxx(f[i][j - 1][l - 1][p], f[i - 1][j][l][p - 1], f[i][j - 1][l][p - 1], f[i - 1][j][l - 1][p]) + a[i][j] + a[l][p];
				}
					
	cout << f[n][m-1][n-1][m];
    return 0;
}