// luogu-judger-enable-o2
// 约数研究.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int a, sum;
int main()
{
	cin >> a;
	for (int i = 1; i <= a; i++)
		sum += a / i;
	cout << sum;
    return 0;
}

