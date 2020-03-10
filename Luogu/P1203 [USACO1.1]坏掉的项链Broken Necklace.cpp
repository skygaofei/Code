// [USACO1.1]坏掉的项链Broken Necklace.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int n,ans=-0x3f3f3f3f;
string s;
int work(int x)
{
	int p = 0;
	char a = s[x], b = s[x + 1];
	for (int i = x;; i--)
	{
		if (s[i] == a)
			p++;
		else if (s[i] == 'w')
			p++;
		else
			break;
	}
	for (int i = x + 1;; i++)
	{
		if (s[i] == b)
			p++;
		else if (s[i] == 'w') p++;
		else break;
	}
	return p;
}
int main()
{
	scanf("%d", &n);
	cin >> s;
	s = s + s + s;
	for (int i = n; i < 2 * n; i++)
	{
		if (s[i] == s[i + 1])
			continue;
		if (s[i] == 'w')
		{
			s[i] = 'r';
			ans = max(ans, work(i));
			s[i] = 'b';
			ans = max(ans, work(i));
			s[i] = 'w';
		}
		ans = max(ans, work(i));
	}
	ans = min(ans, n);
	if (ans == -0x3f3f3f3f)
		ans = n;
	cout << ans << endl;

	return 0;
}

