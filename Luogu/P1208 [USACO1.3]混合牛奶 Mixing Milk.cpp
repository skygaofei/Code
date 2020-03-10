#include<bits/stdc++.h>
using namespace std;
struct nm
{
	int pi;
	int ai;
};
bool px(nm x,nm y)
{
	
		return x.pi<y.pi;
}
int main()
{
	int n,m;
	long sum=0; 
	cin>>n>>m;
	nm a[m+1];
	int i;
	for(i=0;i<m;i++)
	{
		cin>>a[i].pi>>a[i].ai;
	}
	sort(a,a+m,px);
	for(i=0;i<m;i++)
	{
			if(a[i].ai<=n)
			{
				sum=sum+a[i].pi*a[i].ai;
				n=n-a[i].ai;
			}
			else
			{ 
				sum=sum+n*a[i].pi;
				break;
			}
	}
	cout<<sum;
	return 0;
}
