#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int main()
{
	int now=0,tim=0;
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(register int i=1;i<=n;i++)
	{
		if(a[i]>now)
			tim+=(a[i]-now)*6+5+1,now=a[i];
		else if(a[i]==now)
			tim++;
		else if(a[i]<now)
			tim+=(now-a[i])*4+5+1,now=a[i];
	}
	tim+=now*4;
	printf("%d",tim); 
	return 0;
}