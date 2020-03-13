#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#define maxn 805
#define maxm 400010
#define inf 0x7fffffff
using namespace std;
int n, m, d, cnt, counter, s, t;
char str[35];
int head[maxn], vis[maxn];
struct edge 
{
	int to, nxt, val;
	edge() {}
	edge(int x, int y, int z) 
	{ 
		to = x, nxt = y, val = z;
	}
}e[maxm];
inline int id1(int x, int y) 
{
	return (x - 1) * m + y;
}
inline int id2(int x, int y) 
{ 
	return (x - 1) * m + y + n * m; 
}
inline int dis(int x1, int y1, int x2, int y2) 
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
inline void addedge(int x, int y, int z) 
{
	e[cnt] = edge(y, head[x], z); 
	head[x] = cnt++;
	e[cnt] = edge(x, head[y], 0); 
	head[y] = cnt++;
}
inline bool bfs()
{
	queue<int> q; 
	q.push(s); 
	memset(vis, -1, sizeof vis); 
	vis[s] = 1;
	while (!q.empty()) 
	{
		int u = q.front(); 
		q.pop();
		for (int i = head[u]; i != -1; i = e[i].nxt) 
		{
			int v = e[i].to;
			if (e[i].val && vis[v] == -1) 
				vis[v] = vis[u] + 1,q.push(v);
		}
	}
	if (vis[t] != -1)
		return true;
	else
		return false;
}
inline int dfs(int u, int flow)
{
	if (u == t) 
		return flow;
	int flag = 0, w;
	for (int i = head[u]; i != -1; i = e[i].nxt) 
	{
		int v = e[i].to;
		if (vis[v] == vis[u] + 1 && e[i].val) 
		{
			w = dfs(v, min(flow - flag, e[i].val));
			e[i].val -= w; 
			e[i ^ 1].val += w; 
			flag += w;
			if (flag == flow) 
				return flag;
		}
	}
	if (!flag) 
		vis[u] = -1;
	return flag;
}
inline int dinic()
{
	int res = 0;
	while (bfs())
		res += dfs(s, inf);
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &d); 
	memset(head, -1, sizeof head);
	s = 0, t = n * m * 2 + 1;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++) 
			if (str[j] - '0' > 0) 
				addedge(id1(i, j), id2(i, j), str[j] - '0');
	}
	for (int i = 1; i <= n; i++) 
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++) 
			if (str[j] == 'L') 
				addedge(s, id1(i, j), 1), counter++;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (i - d < 1 || i + d > n || j - d < 1 || j + d > m)
				addedge(id2(i, j), t, inf);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= n; k++)
				for (int l = 1; l <= m; l++) 
					if (dis(i, j, k, l) <= d * d) 
						addedge(id2(i, j), id1(k, l), inf);
	printf("%d", counter - dinic());
	return 0;
}