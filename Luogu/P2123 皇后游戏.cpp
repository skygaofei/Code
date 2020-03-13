// 皇后游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
struct Queen
{
	int rig, lef, flag;
	/*bool operator < (const Queen &a) const
	{
		if (div != a.div)
			return div < a.div;
		if (div <= 0)
			return x < a.x;
		return y > a.y;
	}*/
}game[maxn];
int t, n;
long long ans[maxn],tmp;
bool cmp(Queen a, Queen b)
{
	if (a.flag != b.flag)
		return a.flag < b.flag;
	if (a.flag <= 0)
		return a.rig < b.rig;
	return a.lef > b.lef;
}
int main()
{
	read(t);
	while (t--)
	{
		read(n);
		for (re int i = 1; i <= n; i++)
		{
			read(game[i].rig), read(game[i].lef);
			if (game[i].rig > game[i].lef)
				game[i].flag = 1;
			else if (game[i].rig < game[i].lef)
				game[i].flag = -1;
			else
				game[i].flag = 0;
		}
		sort(game + 1, game + n + 1, cmp);
		tmp = 0;
		for (re int i = 1; i <= n; i++)
		{
			tmp += game[i].rig;
			ans[i] = max(ans[i - 1], tmp) + game[i].lef;
		}
		printf("%lld\n", ans[n]);
	}
	return 0;
}

