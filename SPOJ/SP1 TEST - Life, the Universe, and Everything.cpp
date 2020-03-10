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

int main()
{
	int n;
	while (read(n))
	{
		if (n == 42)
			return 0;
		printf("%d\n", n);
	}
	return 0;
}