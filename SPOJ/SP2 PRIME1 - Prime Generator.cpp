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
bool prime(int x)
{
	if (x == 1 || x == 0)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x%i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	read(n);
	int l,r;
	prime(1000000000);
	for (int i = 1; i <= n; i++)
	{
		read(l),read(r);
		for (int j = l; j <= r; j++)
		{
			if (prime(j))
				printf("%d\n", j);
		}
		printf("\n");
	}
	return 0;
}