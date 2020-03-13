// 反素数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int antiprime[] = { 1,2,4,6,12,24,
						36,48,60,120,180,240,
						360,720,840,1260,1680,2520,
						5040,7560,10080,15120,20160,
						25200,27720,45360,50400,55440,
						83160,110880,166320,221760,277200,
						332640,498960,554400,665280,720720,
						1081080,1441440,2162160,2882880,3603600,
						4324320,6486480,7207200,8648640,10810800,
						14414400,17297280,21621600,32432400,36756720,
						43243200,61261200,73513440,110270160,122522400,
						147026880,183783600,245044800,294053760,367567200,
						551350800,698377680,735134400,1102701600,1396755360,2001000000 };
inline bool read(int &num)
{
	char in; 
	bool IsN = false;
	in = getchar();
	if (in == EOF) 
		return false;
	while (in != '-' && (in<'0' || in>'9')) 
		in = getchar();
	if (in == '-') 
	{
		IsN = true;
		num = 0; 
	}
	else
		num = in - '0';
	while (in = getchar(), in >= '0'&&in <= '9') 
		num *= 10, num += in - '0';
	if (IsN) 
		num = -num;
	return true;
}
int main()
{
	register int n;
	read(n);
	for(register int i=1;i;i++)
		if (antiprime[i] > n)
		{
			printf("%d", antiprime[i - 1]);
			return 0;
		}
	return  0;
}
