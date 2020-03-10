#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> v[30];
inline int find_1(int x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < v[i].size(); j++)
			if (v[i][j] == x)
				return i;
}
inline int find_2(int x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < v[i].size(); j++)
			if (v[i][j] == x)
				return j;
}
inline void doo(int x, int h)
{
	for (int i = h + 1; i < v[x].size(); i++)
		v[v[x][i]].push_back(v[x][i]);
	v[x].resize(h + 1);
}
inline void onto(int x, int h, int x1)
{
	for (int i = h; i < v[x].size(); i++)
		v[x1].push_back(v[x][i]);
	v[x].resize(h);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		v[i].push_back(i);
	int a, b;
	string s1, s2;
	while (cin >> s1)
	{
		if (s1 == "quit")
			break;
		cin >> a >> s2 >> b;
		int pa, pb, ha, hb;
		pa = find_1(a); ha = find_2(a);
		pb = find_1(b); hb = find_2(b);
		if (pa == pb)
			continue;
		if (s2 == "onto")
			doo(pb, hb);
		if (s1 == "move")
			doo(pa, ha);
		onto(pa, ha, pb);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d:", i);
		for (int j = 0; j < v[i].size(); j++)
			printf(" %d", v[i][j]);
		printf("\n");
	}
	return 0;
}