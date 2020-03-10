#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=300,in=0,out=0,b=0,money,month=0;
    for(int i=1;i<=12;i++)
    {
		cin>>money;
    	b=a-money;
    	if(b<0)
		{
			month=0-i;
			break;
		}
    	if(b>=100) 
		{
			in=in+b/100*100;
			b=b-b/100*100;
		}
   		a=b+300;
    }
 	if(month<0) 
 		cout<<month;
 	else 
	{
		out=1.2*in;
		cout<<b+out;
	}
	return 0;
}
