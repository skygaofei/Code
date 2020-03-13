// 马的遍历.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<cstdio>
using namespace std;
int n, m, sx, sy, tx, ty, h = 1, t = 1, x, y;
bool vis[500][500];
int step[500][500];
int go[8][2] = { {2,1},{2,-1},{1,2},{-1,2},{-2,-1},{-2,1},{1,-2},{-1,-2} };
struct que
{
	int x, y;
}q[100010];
int main()
{
	cin >> n >> m >> x >> y;
	q[h].x = x;
	q[h].y = y;
	t++;
	while (h < t)
	{
		sx = q[h].x;
		sy = q[h].y;
		for (int i = 0; i < 8; i++)
		{
			tx = sx + go[i][0];
			ty = sy + go[i][1];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty])
			{
				q[t].x = tx;
				q[t].y = ty;
				t++;
				step[tx][ty] = step[sx][sy] + 1;
				vis[tx][ty] = true;
			}
		}
		h++;
	}
	step[x][y] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (step[i][j] == 0 && (i != x || j != y))
			{
				printf("%-5d", -1);
				continue;
			}
			printf("%-5d", step[i][j]);
		}
		cout << endl;
	}
    return 0;
}

