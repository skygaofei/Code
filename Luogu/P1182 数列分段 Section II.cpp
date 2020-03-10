#include<iostream>
using namespace std;
int a[100010], n, m;
bool check(int x)
{
	/*int sum=0, t = 1;
	for (int i = 1; i <= n; i++)
	{
		if (sum + a[i] <= x)
			sum += a[i];
		else
		{
			t++;
			sum = a[i];
		}
	}
	if (t > m)
		return false;
	else
		return true;*/
	int s = 1, s1 = 0;
	while (s <= n)
	{
		int sum = 0;
		while (sum + a[s] <= x && s <= n)
		{
			sum += a[s];
			s++;
		}
		s1++;
	}
	if (s1 > m)
		return false;
	else
		return true;
}
int main()
{
	//freopen("testdata.in", "r", stdin);
	cin >> n >> m;
	int sum = 0, mi = -99999999;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		if (mi < a[i])
			mi = a[i];
	}
	int l, r, mid;
	l = mi;
	r = sum;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (check(mid) == true)
			r = mid;
		else
			l = mid + 1;
	}
	cout << r;
	return 0;
}