#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define maxn 20005
#define re register
using namespace std;
int n, k;
int now;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	string s, tmp;
	while (cin >> tmp)
		s += tmp;
	cout << tmp.length() << ' ';
	now = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if ((int)(s[i] - '0') != now)
		{
			cout << k << ' ';
			k = 1;
			now = (int)(s[i] - '0');
			continue;
		}
		if ((int)(s[i] - '0') == now)
			k++;
	}
	if ((int)(s[s.length() - 1] - '0') == now)
		cout << k;
	return 0;
}