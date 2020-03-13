#include<bits/stdc++.h>
char sa[401],sb[401];
int a[401],b[401],c[402];
int la,lb,j,i;
using namespace std;
int main()
{
	cin>>sa>>sb;
	la=strlen(sa);
	lb=strlen(sb);
	for(i=0;i<la;i++)
		a[i]=sa[la-i-1]-'0';
	for(i=0;i<lb;i++)
		b[i]=sb[lb-i-1]-'0';
	if(la<lb)
		la=lb;
	for(i=0;i<la;i++)
		c[i]=a[i]+b[i];
	for(i=0;i<la;i++)
		if(c[i]>=10)
		{
			c[i+1]=c[i+1]+1;
			c[i]=c[i]-10;
		}
	while(c[la]==0&&la!=0)
		la--;
	for(la;la>=0;la--)
		cout<<c[la];
	return 0;
}