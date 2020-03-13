#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int i,x;
	long long s=0,n;
	cin>>x>>n;
	for(i=1;i<=n;i++)
	{
		if(x%7!=6&&x%7!=0)
			s=s+250;
		x++;
	}
	cout<<s;
	return 0;
}
