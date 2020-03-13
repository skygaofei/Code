// hash.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define ull unsigned long long
#define prime 233317
using namespace std;
ull base = 131, hashh[10010];
ull mod = 212370440130137957ll;
string s;
inline ull cauhash(string x)
{
	int len = x.length();
	ull ans = 0;
	for (register int i = 0; i < len; i++)
		ans = (ans*base + (ull)(x[i])) % mod + prime;
	return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (register int i = 1; i <= n; i++)
	{
		cin >> s;
		hashh[i] = cauhash(s);
	}
	sort(hashh + 1, hashh + n + 1);
	int len = 0;
	for (int i = 1; i <= n; i++)
		if (hashh[i] != hashh[i + 1])
			len++;
	printf("%d", len);
	return 0;
}

