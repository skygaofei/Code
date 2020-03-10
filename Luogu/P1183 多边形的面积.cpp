#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
double x[105],y[105],ans;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	x[n+1]=x[1];
	y[n+1]=y[1];
	for(int i=1;i<=n;i++)
		ans+=0.5*(x[i]*y[i+1]-y[i]*x[i+1]);
	printf("%d",(int)(ans));
	return 0;
}