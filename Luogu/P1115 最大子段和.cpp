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
int a[200001],s[200001];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,ans= -2000000000;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		s[i] = max(s[i - 1] + a[i], a[i]);
	for(int i = 1;i <= n; i++)
			ans = max(ans, s[i]);
	cout << ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}