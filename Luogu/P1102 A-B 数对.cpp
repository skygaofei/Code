#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
map<long long, long long> ma;
long long a[200005];
int main()
{
	int n; long long c, ans = 0;
	scanf("%d%lld", &n, &c);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		ma[a[i]]++;
		a[i] -= c;
	}
	for (int i = 1; i <= n; i++)
		ans += ma[a[i]];
	printf("%lld", ans);
	return 0;
}