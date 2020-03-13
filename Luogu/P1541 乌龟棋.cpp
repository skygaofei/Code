// luogu-judger-enable-o2
#include<iostream>
#include<algorithm>
using namespace std;
int f[50][50][50][50], a[360];
int c[5];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int b[200];
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		c[b[i]]++;
	}
	f[0][0][0][0] = a[1];
	for (int i = 0; i <= c[1]; i++)
		for (int j = 0; j <= c[2]; j++)
			for (int k = 0; k <= c[3]; k++)
				for (int l = 0; l <= c[4]; l++)
				{
					if (i - 1 >= 0)
						f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + a[i + j * 2 + k * 3 + l * 4 + 1]);
					if (j - 1 >= 0)
						f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + a[i + j * 2 + k * 3 + l * 4 + 1]);
					if (k - 1 >= 0)
						f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + a[i + j * 2 + k * 3 + l * 4 + 1]);
					if (l - 1 >= 0)
						f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + a[i + j * 2 + k * 3 + l * 4 + 1]);
				}
	cout << f[c[1]][c[2]][c[3]][c[4]];
    return 0;
}