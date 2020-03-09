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
bool cmp(string a, string b)
{
	return a + b > b + a;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	cin >> n;
	string s[21];
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		cout << s[i];
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}