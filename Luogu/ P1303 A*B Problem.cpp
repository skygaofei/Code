#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a[2001],b[2001],c[4002],i,j,la,lb,lc=4001;

int main()
{
	cin>>s1>>s2;
	if(s1=="0"||s2=="0")
	{
		cout<<"0";
		return 0;
	}
		
	la=s1.length();
	lb=s2.length();

	for(i=1;i<=la;i++)
	{
		a[i]=s1[la-i]-'0';
	}
	for(i=1;i<=lb;i++)
	{
		b[i]=s2[lb-i]-'0';

	}
	for(i=1;i<=la;i++)
	{
		for(j=1;j<=lb;j++)

		{
			c[i+j-1]=c[i+j-1]+b[j]*a[i];

			if(c[i+j-1]>=10)

			{
				c[i+j]=c[i+j]+c[i+j-1]/10;

				c[i+j-1]=c[i+j-1]%10; 
			}
		}
	}
	while(c[lc]==0&&lc!=0)
		lc--;
	for(lc;lc>0;lc--)
		cout<<c[lc];
	return 0;
}