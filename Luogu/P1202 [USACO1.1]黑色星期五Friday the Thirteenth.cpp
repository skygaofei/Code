// 黑色星期五Friday the Thirteenth.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,t[10];
struct WSJR
{
	int year, month, day;
};
bool operator < (const WSJR &a, const WSJR &b)
{
	if (a.year != b.year)
		return a.year < b.year;
	if (a.month != b.month)
		return a.month < b.month;
	return 0;
}
int d[2][13] = { 31,28,31,30,31,30,31,31,30,31,30,31,0,31,29,31,30,31,30,31,31,30,31,30,31,0 };
void operator ++ (WSJR &a)
{
	bool flag = false;
	if (!(a.year % 400))
		flag = true;
	if ((a.year % 100) && !(a.year % 4))
		flag = true;
	a.day += d[flag][a.month++], a.day %= 7;
	if (a.month == 12)
		a.year++, a.month = 0;
}
int main()
{
	scanf("%d", &n);
	WSJR a, b;
	a.year = 1900; a.month = 0; a.day = 5;
	b.year = 1900 + n - 1; b.month = 11; b.day = -1;
	while (!(b < a))
	{
		t[a.day]++;
		++a;
	}
	for (int i = 5; i < 12; i++)
		printf("%d ", t[i % 7]);
	return 0;
}
