#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <iostream> 
#include <cmath> 
#include <queue>
#include <cstring>
#include <vector>
#define re register
#define inf 0x7fffffff
#define maxn 10010
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
int dfs(int x, int low)//x表示当前节点,low表示当前流到x的最小的残量
{
	if (x == t || low == 0)
		return low;
	int totflow = 0;//totflow表示x节点总共流出的流量
	for (re int i = 0; i < e[x].size(); ++i)
	{
		int y = e[x][i].to;
		int rev = e[x][i].rev;
		if (d[y] == d[x] + 1 && e[x][i].val)//y是x的下一层，且当前边有残量>0
		{
			int a = dfs(y, min(low, e[x][i].val));//a表示当前边流出的流量
			e[x][i].val -= a;
			e[y][rev].val += a;
			low -= a;
			totflow += a;
			if (low == 0)//流到x的流量流完了
				return totflow;
		}
	}
	if (low != 0)//优化，直观理解：流到x的流量会有冗余,这一轮dfs之后就再也不到x了
		d[x] = -1;
	return totflow;
}
void dinic()
{
	while (bfs())
		ans += dfs(s, inf);
}
void work(char& x)
{
	if (x >= 'A' && x <= 'Z')
		x -= 'A';
	else
		x =x- 'a' + 30;
}
int main()
{
	scanf("%d", &n);
	int z;
	char x[10], y[10];
	s = 'A'-'A', t = 'Z'-'A';
	for (re int i = 1; i <= n; ++i)
	{
		scanf("%s%s%d", x, y, &z);
		work(x[0]), work(y[0]);
		addedge(x[0], y[0], z);
	}
	dinic();
	printf("%d", ans);
	return 0;
}
