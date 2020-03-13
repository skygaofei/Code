// 仪仗队.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace std;
int oula(int n)
{
	int sum, k;
	if (n == 1)
		sum = 1;
	else
	{
		sum = n;
		k = 1;
		for (int i = 2; n != 1; i += k)
		{
			if (n%i == 0)
			{
				sum /= i;
				sum = sum * (i - 1);
				while (n%i == 0)
					n = n / i;
				i = k;
			}
		}
	}
	return sum;
}
int main()
{
	int ans = 0;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = 3; i <= n; i++)
	{
		ans = ans + oula(i - 1);
	}
	cout << ans * 2 + 3;
    return 0;
}

