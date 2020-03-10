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
inline bool read(long long &num)
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
long long Pow(int x, int y)
{
	long long sum = x;
	for (int i = 1; i < y; i++)
		sum *= x;
	return sum;
}
int main()
{
	long long n;
	read(n);
	long long ans = 0;
	long long x;
	for (int i = 1; i <= n; i++)
	{
		read(x);
		ans = x / Pow(5, 1) + x / Pow(5, 2) + x / Pow(5, 3) + x / Pow(5, 4) + x / Pow(5, 5) + x / Pow(5, 6) + x / Pow(5, 7) + x / Pow(5, 8) + x / Pow(5, 9) + x / Pow(5, 10) + x / Pow(5, 11) + x / Pow(5, 12) + x / Pow(5, 13);
		printf("%lld\n", ans);
	}
	return 0;
}