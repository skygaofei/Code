// luogu-judger-enable-o2
// 手机_NOI导刊2010普及（10）.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
using namespace std;

int num[210];

int main()
{
	num['a'] = 1;
	num['b'] = 2;
	num['c'] = 3;
	num['d'] = 1;
	num['e'] = 2;
	num['f'] = 3;
	num['g'] = 1;
	num['h'] = 2;
	num['i'] = 3;
	num['j'] = 1;
	num['k'] = 2;
	num['l'] = 3;
	num['m'] = 1;
	num['n'] = 2;
	num['o'] = 3;
	num['p'] = 1;
	num['q'] = 2;
	num['r'] = 3;
	num['s'] = 4;
	num['t'] = 1;
	num['u'] = 2;
	num['v'] = 3;
	num['w'] = 1;
	num['x'] = 2;
	num['y'] = 3;
	num['z'] = 4;
	int sum = 0;
	string ans;
	getline(cin, ans);
	for (int i = 0; i < ans.length(); i++)
	{
		if (ans[i] == ' ')
			sum++;
		else
			sum += num[ans[i]];
	}
	cout << sum;
    return 0;
}

