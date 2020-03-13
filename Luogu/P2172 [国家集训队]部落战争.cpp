// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define maxn 20005
#define re register
using namespace std;
int n, m, r, c, f[60][60], num[60][60], cnt;
int gx[4], gy[4];
char s[100];
bool vis[3000];
int lk[3000];
vector<int> e[3000];
bool find(int x)
{
	for (re int i = 0; i < e[x].size(); ++i)
	{
		int y = e[x][i];
		if (!vis[y])
		{
			vis[y] = 1;
			if (!lk[y] || find(lk[y]))
			{
				lk[y] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for (re int i = 1; i <= n; ++i)
	{
		scanf("%s", s + 1);
		for (re int j = 1; j <= m; ++j)
			if (s[j] == '.')
				num[i][j] = ++cnt, f[i][j] = 1;
	}
	gy[0] = -r, gy[1] = -c, gy[2] = c, gy[3] = r;
	gx[0] = c, gx[1] = r, gx[2] = r, gx[3] = c;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			if(f[i][j])
				for (re int k = 0; k < 4; ++k)
				{
					int x = i + gx[k];
					int y = j + gy[k];
					if (f[x][y])
						e[num[i][j]].push_back(num[x][y]);
				}
	int ans = cnt;
	for (re int i = 1; i <= cnt; ++i)
	{
		memset(vis, 0, sizeof(vis));
		if (find(i))
			--ans;
	}
	printf("%d",ans);
	return 0;
}