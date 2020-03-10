// 木棍加工.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#define maxn 5005
#define re register
using namespace std;
namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], str[64];
	int l = SIZE, r = SIZE;
	int read(char *s) {
		while (r) {
			for (; l < r && buf[l] <= ' '; l++);
			if (l < r) break;
			l = 0, r = int(fread(buf, 1, SIZE, stdin));
		}
		int cur = 0;
		while (r) {
			for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
			if (l < r) break;
			l = 0, r = int(fread(buf, 1, SIZE, stdin));
		}
		s[cur] = '\0';
		return cur;
	}
	template<typename type>
	bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
		if (!(len = read(str))) return false;
		if (str[cur] == '-') flag = true, cur++;
		for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
		if (flag) x = -x;
		return true;
	}
	template <typename type>
	type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
		if (!(len = read(str))) return false;
		if (str[cur] == '-') flag = true, cur++;
		for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
		return flag ? -x : x;
	}
} using FastIO::read;
struct stick
{
	int l, w;
}a[maxn]; bool vis[maxn];
bool cmp(stick a, stick b)
{
	if (a.l == b.l)
		return a.w > b.w;
	return a.l > b.l;
}
int main()
{
	re int n;
	read(n);
	for (re int i = 1; i <= n; i++)
		read(a[i].l), read(a[i].w);
	sort(a + 1, a + n + 1, cmp);
	int tmp = 0;
	for (re int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			tmp = a[i].w;
			for(re int j=i+1;j<=n;j++)
				if (a[j].w <= tmp && !vis[j])
				{
					vis[j] = true;
					tmp =a[j].w;
				}
		}
	}
	int ans = 0;
	for (re int i = 1; i <= n; i++)
		if (!vis[i])
			ans++;
	printf("%d", ans);
	return 0;
}

