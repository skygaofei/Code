// luogu-judger-enable-o2
// 禽兽的传染病.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;

long long sum=1, n, x;

int main()
{
	cin >> x >> n;
	for (int i = 1; i <= n; i++)
		sum += sum * x;
	cout << sum;
    return 0;
}

