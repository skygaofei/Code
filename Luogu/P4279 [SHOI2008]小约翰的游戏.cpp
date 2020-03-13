#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#define re register
using namespace std;
int main()
{
	int t,n,ans,cnt,x;
	scanf("%d",&t);
	while(t--)
	{
		cnt=ans=0;
		scanf("%d",&n);
		for(re int i=1;i<=n;++i)
			scanf("%d",&x),ans^=x,cnt+=(x==1);
		if(cnt==n)
		{
			if(n&1)
				printf("Brother\n");
			else
				printf("John\n");
		}
		else
		{
			if(ans>0)
				printf("John\n");
			else
				printf("Brother\n");
		}
	}
	return 0;
}
