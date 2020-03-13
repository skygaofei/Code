#include<bits/stdc++.h>
using namespace std;
int main()
{
	double v,k,s,x;
	cin>>s>>x;
	v=7.0;
	k=0;
	while(k<s-x)
	{
		k=k+v;
		v=v*0.98;
	}
	if(k+v>s+x)
		cout<<'n';
	else
		cout<<'y';
	return 0;
}
