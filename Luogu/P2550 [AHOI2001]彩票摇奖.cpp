#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define maxn 35
#define re register
using namespace std;
int n,x;
int a[maxn],ans[maxn];
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=7;++i)
	{
		scanf("%d",&x);
		a[x]++;
	}
	int tmp;
	for(re int i=1;i<=n;++i)
	{
		tmp=7;
		for(re int j=1;j<=7;++j)
		{
			scanf("%d",&x);
			if(a[x])
				tmp--;
		}
		ans[tmp]++;
	}
	for(re int i=0;i<7;++i)
		printf("%d ",ans[i]);
    return 0;
}
