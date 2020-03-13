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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d<b)
	{
		c=c-1;
		d=d+60;
	}
	cout<<c-a<<' '<<d-b;
	return 0;
}
