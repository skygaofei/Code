#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},b,c;
int pd(int x)
{
	int s1=0;
	do
	{
		s1=s1+a[x%10];
		x=x/10;
	}
	while(x>0);
	return s1;
}
bool o(int b1,int c1,int d,int e)
{
	int s2=0;
	s2=s2+pd(b1);
	s2=s2+pd(c1);
	s2=s2+pd(d);
	if(s2==e)
		return true;
	return false;
}
int main()
{
	int n,s=0;
	cin>>n;
	n=n-4;
	for(b=0;b<=1000;b++)
		for(c=0;c<=1000;c++)
		{
			if(o(b,c,b+c,n))
				s++;
		}
	cout<<s;
	return 0;
}
