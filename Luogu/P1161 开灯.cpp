// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
bool aa[1000001] = { false };

int main()
{
	int n;
	cin >> n;
	double a[n];
	int t[n];
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> t[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= t[i]; j++)
			aa[int(a[i] * j)] = !aa[int(a[i] * j)];
	for (int i = 1; i <= 1000001; i++)
		if (aa[i] == true)
		{
			cout << i;
			return 0;
		}
    return 0;
}

