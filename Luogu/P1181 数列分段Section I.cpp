#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int temp;
	int ans=0;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		if(sum+temp<=m)
			sum+=temp;
		else if(sum+temp>m)
			ans++,sum=temp;
	}
	printf("%d",ans+1);
	return 0;
}