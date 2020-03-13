#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <iostream> 
#include <cmath> 
#include <queue>
#include <cstring>
#include <vector>
#define re register
#define inf 0x3f3f3f3f
#define maxn 10005
#define maxm 100010
using namespace std;
int n, m, s, t;
int sum, ans;
int d[maxn];
struct edge {
	int to, val, rev;
	edge(int _to, int _val, int _rev)
	{
		to = _to;
		val = _val;
		rev = _rev;
	}
};
vector<edge> e[maxn];
void addedge(int x, int y, int w)
{
	e[x].push_back(edge(y, w, e[y].size()));
	e[y].push_back(edge(x, 0, e[x].size() - 1));
}
bool bfs()
{
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (re int i = 0; i < e[x].size(); ++i)
		{
			int y = e[x][i].to;
			if (d[y] == -1 && e[x][i].val > 0)
			{
				q.push(y);
				d[y] = d[x] + 1;
			}
		}
	}
	if (d[t] == -1)
		return false;
	else
		return true;
}
int dfs(int x, int low)
{
	if (x == t || low == 0)
		return low;
	int totflow = 0;
	for (re int i = 0; i < e[x].size(); ++i)
	{
		int y = e[x][i].to;
		int rev = e[x][i].rev;
		if (d[y] == d[x] + 1 && e[x][i].val)
		{
			int a = dfs(y, min(low, e[x][i].val));
			e[x][i].val -= a;
			e[y][rev].val += a;
			low -= a;
			totflow += a;
			if (low == 0)
				return totflow;
		}
	}
	if (low != 0)
		d[x] = -1;
	return totflow;
}
void dinic()
{
	while (bfs())
		ans += dfs(s, inf);
}
int get_num(int x, int y)
{
	return (x - 1)* m + y;
}
int mp[105][105];
int nxt[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int main()
{
	scanf("%d%d", &n, &m);
	s = n*m+1, t = n * m+2;
	int x, y, z;
	for (re int i = 1; i <= n; ++i)
		for (re int j = 1; j <= m; ++j)
		{
			scanf("%d", &mp[i][j]);
			if (mp[i][j] == 2)
				addedge(get_num(i,j), t, inf);
			else if (mp[i][j] == 1)
				addedge(s, get_num(i, j), inf);
		}
	for (re int i = 1; i <= n; ++i)
		for (re int j = 1; j <= m; ++j)
		{
				for (re int k = 0; k < 4; ++k)
				{
					x = i + nxt[k][0], y = j + nxt[k][1];
					if (x >= 1 && x <= n && y >= 1 && y <= m)
						addedge(get_num(i, j), get_num(x, y), 1);
				}
		}
	dinic();
	printf("%d", ans);
	return 0;
}
