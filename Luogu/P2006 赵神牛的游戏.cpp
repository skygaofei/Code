// 赵神牛的游戏.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<sstream>
#include<iomanip>
#include<ctime>
#include<cmath>
#define can true
#define ll long long
using namespace std;
int main()
{
	ll sum_of_magic, sum_of_skill, blood_of_boss, consume[30020], atk[30020];
	bool can_defeat;
	double sum;
	cin >> sum_of_magic >> sum_of_skill >> blood_of_boss;
	for (ll counter = 1; counter <= sum_of_skill; counter++)
		cin >> consume[counter] >> atk[counter];
	for (ll counter = 1; counter <= sum_of_skill; counter++)
	{
		if (atk[counter] > 0 && consume[counter] == 0)
		{
			cout << counter << " ";
			can_defeat = can; 
		}
		else
		{
			if (consume[counter] != 0)  
				sum = sum_of_magic / consume[counter];
			if (atk[counter] * sum >= blood_of_boss)
			{
				cout << counter << ' ';
				can_defeat = can;
			}
		}
	}
	if (!can_defeat)
		cout << -1;
	return 0;
}