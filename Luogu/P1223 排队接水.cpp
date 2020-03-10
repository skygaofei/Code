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
struct MyStruct
{
	int ti, No;
}a[1010];
int  n;
bool cmp(MyStruct a, MyStruct b)
{
	if (a.ti == b.ti)
		return a.No < b.No;
	else
		return a.ti < b.ti;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	double time=0.0000;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].ti;
		a[i].No = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		cout << a[i].No<<' ';
		time += a[i].ti*(n - i);
	}
	cout << endl;
	printf("%.2f", time / n);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}