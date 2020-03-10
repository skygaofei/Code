#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<sstream>
#include<queue>
#include<cmath>
#include<ctime>
#include<string>
#include<cstring>
using namespace std;
int a[31],f[31][20011],sum=2000000000;
int main()
{
	int v, n;
	cin >> v >> n;
	if (v == 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = 1;
		for (int j = 1; j <= v; j++)
		{
			if ((f[i - 1][j - a[i]] == 1 &&j>=a[i])|| f[i - 1][j] == 1)
			{
				f[i][j] = 1;
				sum = min(sum, v - j);
			}	
			else
				f[i][j] = 0;
			
		}
	}
	cout << sum;
	return 0;
}