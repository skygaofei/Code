// P2788 数学1（math1）- 加减算式.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string num;
	cin >> num;
	int l = num.length() - 1;
	int n = 0, ans = 0;
	int s = 0;
	while (num[s] >= '0'&&num[s] <= '9')
	{
		n = n * 10 + num[s] - '0';
		s++;
	}
	ans = n;
	s++;
	char aaa = num[s - 1];
	while (s <= l)
	{
		n = 0;
		while (num[s] >= '0'&&num[s] <= '9')
		{
			n = n * 10 + num[s] - '0';
			s++;
		}
		if (aaa == '+')
		{
			ans += n;
			aaa = num[s];
			s++;
		}
		else if (aaa == '-')
		{
			ans -= n;
			aaa = num[s];
			s++;
		}
	}
	cout << ans;
    return 0;
}

