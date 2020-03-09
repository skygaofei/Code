#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
//#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,n;
	int max1=-1;
	int max2=-1;
	cin>>l>>n;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		int s1=x;
		int s2=l-x+1;
		max1=max(max1,max(s2,s1));
		max2=max(max2,min(s1,s2));
	}
	if(max2==-1&&max1==-1)
	{
		cout<<0<<' '<<0;
		return 0;
	}
	cout<<max2<<' '<<max1;
	return 0;
}