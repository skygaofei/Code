// 求先序排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
void dfs(string a, string b)
{
	if (a.length() > 0)
	{
		char t = b[b.length() - 1];
		cout << t;
		int pos = a.find(t);
		dfs(a.substr(0,pos),b.substr(0,pos));
		dfs(a.substr(pos+1),b.substr(pos,a.length()-pos-1));
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	dfs(a, b);
	return 0;
}
