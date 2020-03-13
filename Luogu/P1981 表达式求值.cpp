// 刷题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
stack<long long> num;
stack<char> cau;
int main()
{
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	string s;
	long long temp;
	long long temp2;
	long long ans;
	while (cin >> s)
	{
		for (int i = 0; i <= s.length()-1; i++)
		{
			temp = 0;
			if (s[i] >= '0'&&s[i] <= '9')
			{
				while (s[i] >= '0'&&s[i] <= '9')
				{
					temp = temp * 10 + ((long long)(s[i] - '0'));
					i++;
				}
				num.push(temp % 10000);
			}
			if (s[i] == '*')
			{
				temp = num.top();
				num.pop();
				temp2 = 0;
				i++;
				while (s[i] >= '0'&&s[i] <= '9')
				{
					temp2 = temp2 * 10 + (long long)(s[i] - '0');
					i++;
				}
				i-=1;
				num.push(temp*temp2%10000);
			}
			if(s[i]=='+')
				cau.push(s[i]);
		}
		ans = num.top();
		num.pop();
		while (!cau.empty())
		{
			ans += num.top();
			num.pop();
			cau.pop();
		}
		printf("%lld\n\n", ans % 10000);
	}
	return 0;
}
