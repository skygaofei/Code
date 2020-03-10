#include<bits/stdc++.h>
using namespace std;
struct student
{
	int y,s,e,sum,num;
};student a[1000],t;
int main()
{
	int n;
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].y>>a[i].s>>a[i].e;
		a[i].sum=a[i].y+a[i].s+a[i].e;
		a[i].num=i;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n+1;j++)
		{
			if(a[i].sum<a[j].sum)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			else if(a[i].sum==a[j].sum)
			{
				if(a[i].y<a[j].y)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
				else if(a[i].y==a[j].y)
				{
					if(a[i].num>a[j].num)
					{
						t=a[i];
						a[i]=a[j];
						a[j]=t;
					}
				}
			}
		}
	for(i=1;i<=5;i++)
	{
		cout<<a[i].num<<' '<<a[i].sum<<endl;
	}
	return 0;
}
