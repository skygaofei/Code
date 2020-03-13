// HXY玩卡片.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x;
	int s_of_0, s_of_5;
	s_of_0 = s_of_5 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x == 0)
			s_of_0++;
		else
			s_of_5++;
	}
	if (s_of_0 == 0)
	{
		cout << -1;
		return 0;
	}
	if (s_of_5 < 9)
	{
		cout << 0;
		return 0;
	}
	s_of_5 = s_of_5 - (s_of_5 % 9);
	for (int i = 1; i <= s_of_5; i++)
		cout << 5;
	for (int i = 1; i <= s_of_0; i++)
		cout << 0;
    return 0;
}

