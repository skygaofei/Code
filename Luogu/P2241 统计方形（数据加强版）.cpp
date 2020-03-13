// 统计方形.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int main()
{
	unsigned long long n, m;
	cin >> n >> m;
	unsigned long long ans = 0;
	for (int i = n, j = m; i >= 1&& j >= 1; i--, j--)
	{
		ans += i * j;
	}
	cout << ans << ' ';
	ans = (n * (n + 1) / 2)*(m*(m + 1) / 2) - ans;
	cout << ans;
	return 0;
}

