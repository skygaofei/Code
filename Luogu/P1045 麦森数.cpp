#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int tmp[1505], sum[1505], ans[1505];
void high1()
{
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= 500; i++)
		for (int j = 1; j <= 500; j++)
			tmp[i + j - 1] += ans[i] * sum[j];
	for (int i = 1; i <= 500; i++) 
	{
		tmp[i + 1] += tmp[i] / 10;
		tmp[i] %= 10;
	}
	memcpy(ans, tmp, sizeof(ans));
}
void high2()
{
	memset(tmp, 0, sizeof(tmp));
	for (int i = 1; i <= 500; i++)
		for (int j = 1; j <= 500; j++)
			tmp[i + j - 1] += sum[i] * sum[j];
	for (int i = 1; i <= 500; i++)
	{
		tmp[i + 1] += tmp[i] / 10;
		tmp[i] %= 10;
	}
	memcpy(sum, tmp, sizeof(sum));
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int p;
	cin >> p;
	cout << (int)(log10(2)*p + 1) << endl;
	ans[1] = 1;
	sum[1] = 2;
	while (p != 0)
	{
		if (p % 2 == 1)
			high1();
		high2();
		p /= 2;
	}
	ans[1] -= 1;
	for (int i = 500; i >= 1; i--)
	{
		if (i != 500 && i % 50 == 0)
			cout << endl << ans[i];
		else
			cout << ans[i];
	}
	return 0;
}