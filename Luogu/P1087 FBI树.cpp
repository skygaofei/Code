// FBI树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
string s;
int n;
void dfs(int l, int r)
{
	if (r > l)
	{
		dfs(l, ((l + r) >> 1));
		dfs(((l + r + 1) >> 1), r);
	}
	bool isb=true, isi=true;
	for (int i = 0; i <= r - l; i++)
		if (s[l + i] == '1')
			isb = false;
		else if (s[l + i] == '0')
			isi = false;
	if (isb)
		cout << "B";
	else if (isi)
		cout << "I";
	else
		cout << "F";
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	dfs(0, s.length()-1);
	return 0;
}
