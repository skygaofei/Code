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
int fa[5011], n, m, p, f1, f2;
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		f1 = find(a);
		f2 = find(b);
		if (f1 != f2)
			fa[f1] = fa[f2];
	}
	for (int i = 1; i <= p; i++)
	{
		int a, b;
		cin >> a >> b;
		f1 = find(a);
		f2 = find(b);
		if (f1 == f2)
			cout << "Yes"<<endl;
		else
			cout << "No"<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}