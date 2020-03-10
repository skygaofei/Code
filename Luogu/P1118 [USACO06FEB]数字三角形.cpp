#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define re register
using namespace std;
int n, sum, ans[20], pastri[20];
bool vis[20];
bool dfs(int pos, int now, int num)
{
	if (num > sum)
		return false;
	if (pos == n&&num==sum)
		if (num == sum)
		{
			ans[pos] = now;
			return true;
		}
		else
			return false;
	vis[now] = true;
	for (re int j = 1; j <= n; j++) 
		if (!vis[j] && dfs(pos + 1, j, num + pastri[pos] * j))
		{
			ans[pos] = now;
			return true;
		}
	vis[now] = false;
	return false;
}
void make_pastri()
{
	for (re int i = 1; i * 2 < n; i++)
		pastri[i] = pastri[n - 1 - i] = (n - i)*pastri[i - 1] / i;
}
int main() 
{
	scanf("%d%d", &n, &sum);
	pastri[0] = pastri[n - 1] = 1;
	make_pastri();
	if (dfs(0, 0, 0))
		for (re int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
	return 0;
}