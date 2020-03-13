#include <bits/stdc++.h>
#define re register
using namespace std;
int n,x,tmp,ans;
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(x>tmp)
			ans+=(x-tmp);
		tmp=x;
	}
	printf("%d",ans);
	return 0;
 } 