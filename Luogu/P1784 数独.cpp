// luogu-judger-enable-o2
#include<iostream>
#include <stdlib.h>
using namespace std;
int map[10][10];
int l[10][10], c[10][10], p[10][4][4], e[10] = { 0,9,9,9,9,9,9,9,9,9 };
void print()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			cout << map[i][j] << ' ';
		cout << endl;
	}
	exit(0);
}
void sudo(int x, int y)
{
	if (x == 9 && y == 9)
	{
		if (map[x][y] != 0)
			print();
		else
			for (int i = 1; i <= 9; i++)
			{
				if (l[i][x] == 0 && c[i][y] == 0 && p[i][(x-1) / 3 + 1][(y-1) / 3 + 1] == 0&&map[x][y]==0)
				{
					map[x][y] = i;
					print();
				}
			}
	}
	if(map[x][y]==0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (l[i][x] == 0 && c[i][y] == 0 && p[i][(x - 1) / 3 + 1][(y - 1) / 3 + 1] == 0)
			{
				map[x][y] = i;
				l[i][x] = 1;
				c[i][y] = 1;
				p[i][(x - 1) / 3 + 1][(y - 1) / 3 + 1] = 1;
				if (y < 9)
					sudo(x, y + 1);
				else
					sudo(x + 1, 1);
				map[x][y] = 0;
				l[i][x] = 0;
				c[i][y] = 0;
				p[i][(x - 1) / 3 + 1][(y - 1) / 3 + 1] = 0;
			}
				
		}
	}
	else if (y < 9)
		sudo(x, y + 1); 
	else 
		sudo(x + 1, 1);
}
int main()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j])
			{
				l[map[i][j]][i] = 1;
				c[map[i][j]][j] = 1;
				p[map[i][j]][(i - 1) / 3 + 1][(j - 1) / 3 + 1] = 1;
			}
		}
	sudo(1, 1);
	return 0;
}
