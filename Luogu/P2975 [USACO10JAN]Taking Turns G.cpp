#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 700005
#define ll long long
int n,a[maxn];
ll f[maxn],g[maxn];
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	f[n]=a[n],g[n]=0;
	ll tmp1,tmp2;
	for(re int i=n-1;i>=1;--i)
	{
		tmp1=g[i+1]+a[i],tmp2=f[i+1];
		if(tmp1>=f[i+1])
			f[i]=tmp1,g[i]=tmp2;
		else
			f[i]=f[i+1],g[i]=g[i+1];
	}
	ll ansx=-1,ansy;
	for(re int i=1;i<=n;++i)
		if(f[i]>ansx)
			ansx=f[i],ansy=g[i];
	printf("%lld %lld",ansx,ansy);
	return 0;
}