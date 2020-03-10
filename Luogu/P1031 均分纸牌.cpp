#include<iostream>
#include<cstdio>
#include<cstdlib>
int n, sum, ans = 0, s;
int a[110], b[110];
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum = sum + a[i];
	}
	s = sum / n;
	for (int i = 1; i<+n; i++)
		a[i] = a[i] - s;
	for (int i = 1; i <= n - 1; i++)
	{
		if (a[i] == 0)
			continue;
		else
		{
			ans++;
			a[i + 1] += a[i];
		}
	}
	printf("%d", ans);
	return 0;
}