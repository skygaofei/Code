#include<bits/stdc++.h>
using namespace std;
struct aa
{
	int k;
	int s;
};
aa a[100001],t;
void px(int l,int r)
{
	int i,j;
	for(i=l;i<r;i++)
		for(j=i+1;j<=r;j++)
		{
			if(a[i].s==a[j].s)
			{
				if(a[i].k>a[j].k)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
					
			}
			if(a[i].s<a[j].s)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
}
int main()
{
	int n,m,h,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].k>>a[i].s;
	px(1,n);
	m=m*1.5;
	h=a[m].s;
	k=m;
	while(a[k].s==a[k+1].s)
		k++;
	cout<<h<<' '<<k<<endl;
	for(int j=1;j<=k;j++)
		cout<<a[j].k<<' '<<a[j].s<<endl;
	return 0;
}
