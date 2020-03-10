#include<bits/stdc++.h>
using namespace std;
typedef pair <long long, int> pii;
typedef long long int LL;
const int MAXN = 300005, MAXM = 300005, INF = 1000000001;

int g[MAXN], to[MAXM << 1], nxt[MAXM << 1], val[MAXM << 1];
int edgeSize, src, n, m, prev[MAXN]; LL d[MAXN]; bool vis[MAXN];
priority_queue <pii, vector <pii>, greater <pii> > q;

void addEdge(int u, int v, int w){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
	val[edgeSize] = w;
}
int main(){
	edgeSize = 1;
	val[1] = INF;
	int i, u, v, w, p; pii now;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w), addEdge(v, u, w);
	} scanf("%d", &src);
	memset(d, 0x3f, sizeof(d));
	q.push(pii(d[src] = 0, src));
	for(i = 1; i <= n; ++ i){
		while(vis[q.top().second]) q.pop();
		now = q.top(); q.pop();
		vis[now.second] = true;
		for(p = g[now.second]; p; p = nxt[p])
			if((d[to[p]] > now.first + val[p]) || (d[to[p]] == now.first + val[p] && val[p] < val[prev[to[p]]])){
				d[to[p]] = now.first + val[p];
				q.push(pii(d[to[p]], to[p]));
				prev[to[p]] = p;
			}
	} LL sum = 0LL;
	for(i = 1; i <= n; ++ i)
		if(i != src) sum += val[prev[i]];
	printf("%I64d\n", sum);
	for(i = 1; i <= n; ++ i)
		if(i != src) printf("%d ", prev[i] >> 1);
   	return 0;
}

