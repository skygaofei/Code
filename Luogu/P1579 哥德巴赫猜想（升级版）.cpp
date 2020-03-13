#include<bits/stdc++.h>
using namespace std;
bool zs(int a)
{
	int i;
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
			return false;
	}
	return true;
}
int main()
{
	int n,i1,i2,i3;
	cin>>n;
	for(i1=2;i1<=n-4;i1++)
		for(i2=2;i2<=n-4;i2++)
		{
			i3=n-i1-i2;
			if((zs(i1)&&zs(i2)&&zs(i3))==0)
				continue;
			cout<<i1<<' '<<i2<<' '<<i3;
			return 0; 
		}
	return 0;
}
