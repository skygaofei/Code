#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
int a[110], f[10010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n, m;
	cin >> n >> m;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= a[i]; j--)
			f[j] += f[j - a[i]];
	}
	cout << f[m];
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}