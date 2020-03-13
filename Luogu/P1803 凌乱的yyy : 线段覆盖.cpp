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
struct y
{
	int start, end;
}yyy[1000011];
bool cmp(y a, y b)
{
	return a.end <b.end;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,s=1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> yyy[i].start >> yyy[i].end;
	sort(yyy + 1, yyy + n + 1, cmp);
	int l = yyy[1].end;
	for (int i = 2; i <= n; i++)
	{
		if (l <= yyy[i].start)
		{
			s++;
			l = yyy[i].end;
		}
	}
	cout << s;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}