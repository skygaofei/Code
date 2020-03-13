#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define re register
#define ll long long
#define maxn 100005
using namespace std;
priority_queue<ll> q;
pair<ll,int> p[maxn];
int n,cnt,ans;
ll m;
int main()
{
	ll x,y;
	scanf("%d%lld",&n,&m);
	for(re int i=1;i<=n;++i)
		scanf("%lld%d",&x,&y),p[i]=make_pair(x,y);
	sort(p+1,p+n+1);
	for(re int i=1;i<=n;++i)
	{
		m-=(p[i].first-p[i-1].first);
		q.push(p[i].second);
		cnt++;
		m-=p[i].second;
		while(!q.empty()&&m<0)
		{
			cnt--,m+=q.top();
			q.pop();
		}
		if(m<0)
			break;
			ans=max(ans,cnt);
	}
	printf("%d",ans);
	/*for(re int i=1;i<=n;++i)
		printf("%lld %d\n",p[i].first,p[i].second);*/
	return 0;
}
