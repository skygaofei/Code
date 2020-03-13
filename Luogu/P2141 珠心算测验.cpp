#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#define re register
using namespace std;
int n,a[105];
bool vis[10005];
int main()
{
	bool flag;int cnt=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(re int i=1;i<n;++i)
		for(re int j=i+1;j<=n;++j)
			for(re int k=1;k<=n;++k)
				if(k!=i&&k!=j)
					if(a[i]+a[j]==a[k])
						cnt++,cnt-=vis[a[k]],vis[a[k]]=true;
	printf("%d",cnt);
	return 0;
}