// 新二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define re register
using namespace std;
int n;
vector<char> son[128];
void dfs(char s)
{
	cout << s;
	for (int i = 0; i < son[s].size(); i++)
		dfs(son[s][i]);
}
int main()
{
	scanf("%d", &n);
	char s[10];
	char sta;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		if (i == 1)
			sta = s[0];
		if (s[0] != '*' && s[1] != '*')
			son[s[0]].push_back(s[1]);
		if (s[0] != '*'&&s[2] != '*')
			son[s[0]].push_back(s[2]);
	}
	dfs(sta);
	return 0;
}

