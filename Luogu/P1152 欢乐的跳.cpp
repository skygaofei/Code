// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool b[101000] = { 0 };
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		b[abs(a[i] - a[i + 1])] = true;
	for(int i=1;i<n;i++)
		if (b[i] != true)
		{
			cout << "Not jolly";
			return 0;
		}
	cout << "Jolly";
    return 0;
}

