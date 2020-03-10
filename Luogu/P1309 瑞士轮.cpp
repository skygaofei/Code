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
int n;
struct racer
{
	int score, power,number;
}s1[200010],s2[200010],s[200010];
bool cmp(racer a, racer b)
{
	return (a.score > b.score || (a.score == b.score&&a.number < b.number));
}
int main()
{
	int  r, q;
	cin >> n >> r >> q;
	for (int i = 1; i <= n * 2; i++)
	{
		cin >> s[i].score;
		s[i].number = i;
	}
	for (int i = 1; i <= n * 2; i++)
		cin >> s[i].power;
		
	sort(s + 1, s + (n * 2 + 1), cmp);
	while (r--)
	{
		for(int i=1;i<=n;i++)
			if (s[i * 2 - 1].power < s[i * 2].power)
			{
				s[i * 2].score++;
				s1[i] = s[i * 2];
				s2[i] = s[i * 2 - 1];
			}
			else
			{
				s[i * 2 - 1].score++;
				s1[i] = s[i * 2 - 1];
				s2[i] = s[i * 2];
			}
		int x = 1, y = 1, i = 1;
		while (x <= n&&y <= n)
		{
			if (cmp(s1[x], s2[y]))
				s[i++] = s1[x++];
			else
				s[i++] = s2[y++];
		}
		while (x <= n)
			s[i++] = s1[x++];
		while (y <= n)
			s[i++] = s2[y++];
	}
	cout << s[q].number;
	return 0;
}