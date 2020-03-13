#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int i;
	int a,b,c;
	cin>>a>>b>>c; 
	int k=0;
	for(i=1;i<=999;i++)
	{
		int n1[4]={0},n2[4]={0},n3[4]={0};
		n1[1]=a*i/100;
		n1[2]=a*i/10%10;
		n1[3]=a*i%10;
		n2[1]=b*i/100;
		n2[2]=b*i/10%10;
		n2[3]=b*i%10;
		n3[1]=c*i/100;
		n3[2]=c*i/10%10;
		n3[3]=c*i%10;
		if(n1[1]*n1[2]*n1[3]*n2[1]*n2[2]*n2[3]*n3[1]*n3[2]*n3[3]==362880&&n1[1]+n1[2]+n1[3]+n2[1]+n2[2]+n2[3]+n3[1]+n3[2]+n3[3]==45)
		{
				cout<<i*a<<' '<<i*b<<' '<<i*c<<endl;
				k++;
		}
	}
	if(k==0)
		cout<<"No!!!";
	return 0;
}
