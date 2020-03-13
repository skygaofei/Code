// Project2.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int n, m, l, r;
int f[1000010];
bool unprime[1000010];
void make_prime(int n)
{
	f[1] = 0;
	unprime[1] = true;
	for (int i = 2; i <= n; i++)
	{
		if (unprime[i] == false)
		{
			f[i] = f[i - 1] + 1;
			for (int j = i + i; j <= n; j += i)
				unprime[j] = true;
		}
		else
			f[i] = f[i - 1];
	}
}
int main()
{
	cin >> n >> m;
	make_prime(m);
	for (int i = 1; i <= n; i++)
	{
		cin >> l >> r;
		if (l < 1 || r > m)
		{
			cout << "Crossing the line" << endl;
		}
		else
		{
			int y = f[r] - f[l];
			if (unprime[l] == false)
				y++;
			cout << y << endl;
		}
	}
    return 0;
}

