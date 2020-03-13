#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int go[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };
int map[107][107], val[107][107];
int n, m, x, y, c;
void dfs(int x, int y, int tag)
{
	for (int i = 0; i < 4; i++)
	{
		int dx = x + go[i][0], dy = y + go[i][1];
		if (dx <= n && dx > 0 && dy <= n && dy > 0)
		{
			if (map[dx][dy] == -1)
			{
				if (val[x][y] + 2 < val[dx][dy]&& tag)
				{
					val[dx][dy] = val[x][y] + 2; 
					map[dx][dy] = map[x][y];
					dfs(dx, dy, 0); 
					map[dx][dy] = -1;
				}
			}
			else if (map[dx][dy] == map[x][y]&&val[x][y] < val[dx][dy])
			{
					val[dx][dy] = val[x][y];
					dfs(dx, dy, 1);
			}
			else if (map[dx][dy] != map[x][y]&&val[x][y] + 1 < val[dx][dy])
			{
					val[dx][dy] = val[x][y] + 1;
					dfs(dx, dy, 1); 
			}
		}
	}
}

int main()
{
	for(int i=0;i<107;i++)
		for (int j = 0; j < 107; j++)
		{
			map[i][j] = -1;
			val[i][j] = inf;
		}
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> c;
		map[x][y] = c;
	}
	val[1][1] = 0;
	dfs(1, 1, 1);
	if (val[n][n] == inf)
		cout << -1;
	else
		cout << val[n][n];
	return 0;
}