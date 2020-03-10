#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct MyStruct
{
	int x, y, ti, num;
}nut[1000010];
int a[1010][1010];
int m, n, t, s, st, sum;
int main()
{
	s = 1;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] > 0)
			{
				nut[s].x = i;
				nut[s].y = j;
				nut[s].num = a[i][j];
				s++;
			}
		}
	for (int i = 1; i < s; i++)
		for (int j = i + 1; j <= s; j++)
			if (nut[i].num < nut[j].num)
				swap(nut[i], nut[j]);
	for (int i = 1; i <= s; i++)
	{
		st = nut[i].x;
		if (i == 1)
			nut[i].ti = nut[i].x + 1;
		else
			nut[i].ti = nut[i - 1].ti + abs(nut[i].x - nut[i - 1].x) + abs(nut[i].y - nut[i - 1].y) + 1;
		if (nut[i].ti + st <= t)
			sum += nut[i].num;
	}
	cout << sum;
	return 0;
}