// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int t, n;
	cin >> t >> n;
swap(t,n);
	int c[30010], f[30010] = { 0 }, w[30010];
	for (int i = 1; i <= n; i++)
		cin >> c[i] >> w[i];
	for (int i = 1; i <= n; i++) 
		for (int j = t; j >= c[i]; j--)
		{
			f[j] = max(f[j], f[j -c[i]] + w[i]);
		}
	cout << f[t];
	return 0;
}