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
struct money
{
	string name;
	int testscore;
	int classscore;
	char stu;
	char west;
	int text;
	int mon;
}a[110]; money ans; int cnt;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	cin >> n;
	ans.classscore = ans.mon = ans.testscore = ans.text = -999999;
	for (int i = 1; i <= n; i++)
		cin >> a[i].name >> a[i].testscore >> a[i].classscore >> a[i].stu >> a[i].west >> a[i].text;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].testscore > 80 && a[i].text >= 1)
			a[i].mon += 8000;
		if (a[i].testscore > 85 && a[i].classscore > 80)
			a[i].mon += 4000;
		if (a[i].testscore > 90)
			a[i].mon += 2000;
		if (a[i].testscore > 85 && a[i].west == 'Y')
			a[i].mon += 1000;
		if (a[i].classscore > 80 && a[i].stu == 'Y')
			a[i].mon += 850;
		if (a[i].mon > ans.mon)
		{
			ans.mon = a[i].mon;
			ans.name = a[i].name;
		}
		cnt += a[i].mon;
	}
	cout << ans.name << endl << ans.mon << endl << cnt;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}