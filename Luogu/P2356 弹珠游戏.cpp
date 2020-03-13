// luogu-judger-enable-o2
// 水体专用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
//#include <map>
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
int map[1050][1050], ans = -0x3f3f3f3f, temp;
int main()
{
	int n;
	read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			read(map[i][j]);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 0)
			{
				temp = 0;
				for (int k = 1; k <= n; k++)
					temp += map[i][k] + map[k][j];
				ans = max(ans, temp);
			}
		}
	if (ans == -0x3f3f3f3f)
		printf("Bad Game!");
	else
		printf("%d", ans);
	return 0;
}

