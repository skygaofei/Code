#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10],i,b,s=0;
	for(i=0;i<=9;i++)
		cin>>a[i];
	cin>>b;
	for(i=0;i<=9;i++)
	{
		if(b>=a[i]||b+30>=a[i])
			s++;
	}
	cout<<s;
	return 0;
}
