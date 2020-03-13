// Cantor表（升级版）.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int num1, num2;
	int n1, n2;
	char p;
	scanf("%d", &num1);
	p = getchar();
	scanf("%d", &num2);
	scanf("%d", &n1);
	p = getchar();
	scanf("%d", &n2);
	int c1, c2;
	c1 = num1 * n1;
	c2 = num2 * n2;
	cout << c2 / __gcd(c1, c2) << ' ' << c1 / __gcd(c1, c2);
    return 0;
}

