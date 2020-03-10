#include<bits/stdc++.h>
using namespace std;
int n,k,num[21],s;
bool prime(int x)
{
	if(x==1||x==0)
		return false;
	else
		for(int i=2;i<=sqrt(x);i++)
			if(x%i==0)
				return false;
	return true;
}
void dg(int s1,int s2,int sum)
{
	if(prime(sum)&&s2==k+1)
		s++;
	else if(s2==k+1)
		return ;
	else
	{
		for(int i=s1;i<=n;i++)
			dg(i+1,s2+1,sum+num[i]);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	dg(1,1,0);
	cout<<s;
	return 0;
 } 