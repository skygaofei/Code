#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
#include<stack>
using namespace std;
int n, a[1100][1100], f[1100][1100];
bool vis[1100][1100];
//int dfs(int x, int y)
//{
//	if (x == n + 1)
//		return 0;
//	if (vis[x][y])
//		return f[x][y];
//	vis[x][y] = 1;
//	f[x][y] = a[x][y] + max(dfs(x + 1, y), dfs(x + 1, y + 1));
//}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	//cout << dfs(1, 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = max(f[i - 1][j - 1], f[i-1][j]) + a[i][j];
	int ans;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[n][i]);
	cout << ans;
	return 0;
}