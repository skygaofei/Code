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
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	stack<char> s;
	bool flag = false;
	string s1;
	getline(cin, s1, '@');
	for (int i = 0; i < s1.length(); i++)
	{

		if (s1[i] == '(')
		{
			s.push(s1[i]);
			flag = true;
		}
		else if (s1[i] == ')')
		{
			if (s.empty())
			{
				cout << "NO";
				return 0;
			}
			s.pop();
		}
	}
	if (s.empty()&&flag)
		cout << "YES";
	else
		cout << "NO";
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}