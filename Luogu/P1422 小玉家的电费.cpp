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
	double a;
	cin>>a;
	if(a<=150)
	{
		printf("%.1lf",a*0.4463);
	}
	if(a>=151&&a<=400)
	{
		printf("%.1lf",150*0.4463+(a-150)*0.4663);
	}
	if(a>=401)
	{
		printf("%.1lf",150*0.4463+250*0.4663+(a-400)*0.5663);
	}
	return 0;
}
