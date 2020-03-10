#include<bits/stdc++.h>
using namespace std;
int main()//-64
{
	char hx[6],dw[6];
	int a[6],b[6],i,s,k;
	long long c,d;
	cin>>hx>>dw;
	s=strlen(hx);
	k=strlen(dw);
	for(i=0;i<s;i++)
		a[i]=hx[i]-64;
	for(i=0;i<k;i++)
		b[i]=dw[i]-64;
	c=1;d=1;
	for(i=0;i<s;i++)
	{
		c=c*a[i];
	}
	for(i=0;i<k;i++)
		d=d*b[i];
	if(c%47==d%47)
		cout<<"GO";
	else
		cout<<"STAY";
	return 0;
}
