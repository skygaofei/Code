#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <stack>
using namespace std;
inline bool read(int &num)
{
	char in; bool IsN = false;
	in = getchar();
	if (in == EOF) return false;
	while (in != '-' && (in<'0' || in>'9')) in = getchar();
	if (in == '-') { IsN = true; num = 0; }
	else num = in - '0';
	while (in = getchar(), in >= '0'&&in <= '9') {
		num *= 10, num += in - '0';
	}
	if (IsN) num = -num;
	return true;
}
string s;
void go()
{
	stack<char> p;
	int l = s.length() - 1;
	for (int i = 0; i <= l; i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')
			printf("%c", s[i]);
		else if (s[i] != ')')
			p.push(s[i]);
		else
		{
			while (p.top() != '(')
			{
				printf("%c", p.top());
				p.pop();
			}
			p.pop();
		}
	}
	printf("\n");
}
int main()
{
	int n;
	read(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		go();
	}
	return 0;
}