// 过河卒.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
long long f[25][25] = { 1 };
bool flag[25][25];
int nex[2][9] = { {0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1} };
using namespace std;
int main()
{
	int sx, sy, tx, ty;
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	for (int i = 0; i <= 8; i++)
		if (tx + nex[0][i] >= 0 && tx + nex[0][i] <= sx && ty + nex[1][i] >= 0 && ty + nex[1][i] <= sy)
			flag[tx + nex[0][i]][ty + nex[1][i]]=1;
	for(int i=0;i<=sx;i++)
		for (int j = 0; j <= sy; j++)
		{
			if (i > 0)
				f[i][j] += f[i - 1][j];
			if (j > 0)
				f[i][j] += f[i][j - 1];
			f[i][j] *= (!flag[i][j]);
		}
	printf("%lld", f[sx][sy]);
	return 0;
}