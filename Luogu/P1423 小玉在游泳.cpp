#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i;
    double a,b=2.0; 
    cin>>a;
    for(i=0;a>=0.0;i++,b*=0.98)
   	{
  		a=a-b;	
	} 
	cout<<i;
	return 0;
}
